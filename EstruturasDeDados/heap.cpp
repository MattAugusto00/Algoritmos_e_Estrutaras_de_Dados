#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Heap {
private:
    vector<T> heapArray;
    int tamanho;

    int getIndicePai(int indice) const {
        return (indice - 1) / 2;
    }

    int getIndiceFilhoEsquerdo(int indice) const {
        return 2 * indice + 1;
    }

    int getIndiceFilhoDireito(int indice) const {
        return 2 * indice + 2;
    }

    void ajustarParaCima(int indice) {
        if (indice == 0) {
            return;
        }

        int indicePai = getIndicePai(indice);
        if (heapArray[indicePai] < heapArray[indice]) {
            swap(heapArray[indicePai], heapArray[indice]);
            ajustarParaCima(indicePai);
        }
    }

    void ajustarParaBaixo(int indice) {
        int indiceMaior = indice;
        int indiceFilhoEsquerdo = getIndiceFilhoEsquerdo(indice);
        int indiceFilhoDireito = getIndiceFilhoDireito(indice);

        if (indiceFilhoEsquerdo < tamanho && heapArray[indiceFilhoEsquerdo] > heapArray[indiceMaior]) {
            indiceMaior = indiceFilhoEsquerdo;
        }

        if (indiceFilhoDireito < tamanho && heapArray[indiceFilhoDireito] > heapArray[indiceMaior]) {
            indiceMaior = indiceFilhoDireito;
        }

        if (indiceMaior != indice) {
            swap(heapArray[indice], heapArray[indiceMaior]);
            ajustarParaBaixo(indiceMaior);
        }
    }

public:
    Heap() : tamanho(0) {}

    void inserir(T dado) {
        heapArray.push_back(dado);
        tamanho++;
        ajustarParaCima(tamanho - 1);
    }

    T extrairMaximo() {
        if (estaVazio()) {
            throw runtime_error("O Heap esta vazio. Nao eh possível extrair o maximo.");
        }

        T maximo = heapArray[0];
        heapArray[0] = heapArray[tamanho - 1];
        heapArray.pop_back();
        tamanho--;
        ajustarParaBaixo(0);

        return maximo;
    }

    T getMaximo() const {
        if (estaVazio()) {
            throw runtime_error("O Heap está vazio. Não ha maximo para obter.");
        }

        return heapArray[0];
    }

    bool estaVazio() const {
        return tamanho == 0;
    }

    int getTamanho() const {
        return tamanho;
    }
};

int main() {
    Heap<int> heap;

    // Exemplo de uso
    heap.inserir(10);
    heap.inserir(5);
    heap.inserir(20);
    heap.inserir(15);

    cout << "Tamanho do Heap: " << heap.getTamanho() << endl; // Deve imprimir: 4
    cout << "Elemento maximo: " << heap.getMaximo() << endl; // Deve imprimir: 20

    while (!heap.estaVazio()) {
        cout << "Extraindo maximo: " << heap.extrairMaximo() << endl;
    }

    return 0;
}
