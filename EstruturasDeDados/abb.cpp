#include <iostream>
using namespace std;

template<typename T>
class No {
public:
    T dado;
    No<T>* esquerda;
    No<T>* direita;

    No(T dado) : dado(dado), esquerda(nullptr), direita(nullptr) {}
};

template<typename T>
class ABB {
private:
    No<T>* raiz;

    No<T>* inserir(No<T>* no, T dado) {
        if (no == nullptr) {
            return new No<T>(dado);
        }

        if (dado < no->dado) {
            no->esquerda = inserir(no->esquerda, dado);
        } else if (dado > no->dado) {
            no->direita = inserir(no->direita, dado);
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
            if (no->esquerda == nullptr) {
                No<T>* temp = no->direita;
                delete no;
                return temp;
            } else if (no->direita == nullptr) {
                No<T>* temp = no->esquerda;
                delete no;
                return temp;
            }

            No<T>* temp = encontrarMin(no->direita);
            no->dado = temp->dado;
            no->direita = remover(no->direita, temp->dado);
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
    ABB() : raiz(nullptr) {}

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
    ABB<int> abb;

    // Exemplo de uso
    abb.inserir(50);
    abb.inserir(30);
    abb.inserir(70);
    abb.inserir(20);
    abb.inserir(40);

    cout << "Arvore em ordem: ";
    abb.percorrerEmOrdem(); // Deve imprimir: 20 30 40 50 70

    abb.remover(30);
    cout << "Arvore em ordem apos remover 30: ";
    abb.percorrerEmOrdem(); // Deve imprimir: 20 40 50 70

    cout << "Encontrou o elemento 40? " << (abb.buscar(40) ? "Sim" : "Nao") << endl; // Deve imprimir: Sim
    cout << "Encontrou o elemento 60? " << (abb.buscar(60) ? "Sim" : "Nao") << endl; // Deve imprimir: Não

    return 0;
}
