#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class No {
public:
    T dado;
    No<T>* esquerda;
    No<T>* direita;
    int altura;

    No(T dado) : dado(dado), esquerda(nullptr), direita(nullptr), altura(1) {}
};

template<typename T>
class AVL {
private:
    No<T>* raiz;

    int getAltura(No<T>* no) const {
        return (no == nullptr) ? 0 : no->altura;
    }

    int calcularBalanceamento(No<T>* no) const {
        return (no == nullptr) ? 0 : getAltura(no->esquerda) - getAltura(no->direita);
    }

    No<T>* rotacaoDireita(No<T>* y) {
        No<T>* x = y->esquerda;
        No<T>* T2 = x->direita;

        x->direita = y;
        y->esquerda = T2;

        y->altura = 1 + max(getAltura(y->esquerda), getAltura(y->direita));
        x->altura = 1 + max(getAltura(x->esquerda), getAltura(x->direita));

        return x;
    }

    No<T>* rotacaoEsquerda(No<T>* x) {
        No<T>* y = x->direita;
        No<T>* T2 = y->esquerda;

        y->esquerda = x;
        x->direita = T2;

        x->altura = 1 + max(getAltura(x->esquerda), getAltura(x->direita));
        y->altura = 1 + max(getAltura(y->esquerda), getAltura(y->direita));

        return y;
    }

    No<T>* inserir(No<T>* no, T dado) {
        if (no == nullptr) {
            return new No<T>(dado);
        }

        if (dado < no->dado) {
            no->esquerda = inserir(no->esquerda, dado);
        } else if (dado > no->dado) {
            no->direita = inserir(no->direita, dado);
        } else {
            return no; // Não permitir chaves duplicadas
        }

        no->altura = 1 + max(getAltura(no->esquerda), getAltura(no->direita));

        int balanceamento = calcularBalanceamento(no);

        // Casos de desbalanceamento e rotações
        if (balanceamento > 1 && dado < no->esquerda->dado) {
            return rotacaoDireita(no);
        }

        if (balanceamento < -1 && dado > no->direita->dado) {
            return rotacaoEsquerda(no);
        }

        if (balanceamento > 1 && dado > no->esquerda->dado) {
            no->esquerda = rotacaoEsquerda(no->esquerda);
            return rotacaoDireita(no);
        }

        if (balanceamento < -1 && dado < no->direita->dado) {
            no->direita = rotacaoDireita(no->direita);
            return rotacaoEsquerda(no);
        }

        return no;
    }

    No<T>* encontrarMin(No<T>* no) {
        while (no->esquerda != nullptr) {
            no = no->esquerda;
        }
        return no;
    }

    No<T>* remover(No<T>* no, T dado) {
        if (no == nullptr) {
            return nullptr;
        }

        if (dado < no->dado) {
            no->esquerda = remover(no->esquerda, dado);
        } else if (dado > no->dado) {
            no->direita = remover(no->direita, dado);
        } else {
            if (no->esquerda == nullptr || no->direita == nullptr) {
                No<T>* temp = (no->esquerda) ? no->esquerda : no->direita;
                if (temp == nullptr) {
                    temp = no;
                    no = nullptr;
                } else {
                    *no = *temp;
                }
                delete temp;
            } else {
                No<T>* temp = encontrarMin(no->direita);
                no->dado = temp->dado;
                no->direita = remover(no->direita, temp->dado);
            }
        }

        if (no == nullptr) {
            return nullptr;
        }

        no->altura = 1 + max(getAltura(no->esquerda), getAltura(no->direita));

        int balanceamento = calcularBalanceamento(no);

        // Casos de desbalanceamento e rotações
        if (balanceamento > 1 && calcularBalanceamento(no->esquerda) >= 0) {
            return rotacaoDireita(no);
        }

        if (balanceamento > 1 && calcularBalanceamento(no->esquerda) < 0) {
            no->esquerda = rotacaoEsquerda(no->esquerda);
            return rotacaoDireita(no);
        }

        if (balanceamento < -1 && calcularBalanceamento(no->direita) <= 0) {
            return rotacaoEsquerda(no);
        }

        if (balanceamento < -1 && calcularBalanceamento(no->direita) > 0) {
            no->direita = rotacaoDireita(no->direita);
            return rotacaoEsquerda(no);
        }

        return no;
    }

    void percursoEmOrdem(No<T>* no) {
        if (no == nullptr) {
            return;
        }

        percursoEmOrdem(no->esquerda);
        cout << no->dado << " ";
        percursoEmOrdem(no->direita);
    }

public:
    AVL() : raiz(nullptr) {}

    void inserir(T dado) {
        raiz = inserir(raiz, dado);
    }

    void remover(T dado) {
        raiz = remover(raiz, dado);
    }

    bool buscar(T dado) const {
        No<T>* atual = raiz;
        while (atual != nullptr) {
            if (dado == atual->dado) {
                return true;
            } else if (dado < atual->dado) {
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        }
        return false;
    }

    void percorrerEmOrdem() {
        percursoEmOrdem(raiz);
        cout << endl;
    }
};

int main() {
    AVL<int> avl;

    // Exemplo de uso
    avl.inserir(50);
    avl.inserir(30);
    avl.inserir(70);
    avl.inserir(20);
    avl.inserir(40);

    cout << "Arvore em ordem: ";
    avl.percorrerEmOrdem(); // Deve imprimir: 20 30 40 50 70

    avl.remover(30);
    cout << "Arvore em ordem apos remover 30: ";
    avl.percorrerEmOrdem(); // Deve imprimir: 20 40 50 70

    cout << "Encontrou o elemento 40? " << (avl.buscar(40) ? "Sim" : "Nao") << endl; // Deve imprimir: Sim
    cout << "Encontrou o elemento 60? " << (avl.buscar(60) ? "Sim" : "Nao") << endl; // Deve imprimir: Não

    return 0;
}
