#include <iostream>
using namespace std;

template<typename T>
class No {
public:
    T data;
    No<T>* next;

    No(T data) : data(data), next(nullptr) {}
};

template<typename T>
class Pilha {
private:
    No<T>* topo;

public:
    Pilha() : topo(nullptr) {}

    ~Pilha() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return topo == nullptr;
    }

    void push(T data) {
        No<T>* novoNo = new No<T>(data);
        if (isEmpty()) {
            topo = novoNo;
        } else {
            novoNo->next = topo;
            topo = novoNo;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "A pilha está vazia. Não é possível realizar pop()." << endl;
        } else {
            No<T>* temp = topo;
            topo = topo->next;
            delete temp;
        }
    }

    T peek() const {
        if (isEmpty()) {
            cout << "A pilha está vazia. Não é possível realizar peek()." << endl;
            return T(); // Retornando um valor padrão (0 para tipos numéricos, vazio para strings, etc.)
        } else {
            return topo->data;
        }
    }
};

int main() {
    Pilha<int> pilha;

    // Exemplo de uso
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "Elemento no topo da pilha: " << pilha.peek() << endl;

    pilha.pop();

    cout << "Elemento no topo apos pop: " << pilha.peek() << endl;

    return 0;
}
