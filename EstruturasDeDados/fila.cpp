#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class Fila {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    Fila() : front(nullptr), rear(nullptr), size(0) {}

    ~Fila() {
        clear();
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "A fila está vazia. Não é possível realizar dequeue()." << endl;
        } else {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    T peek() const {
        if (isEmpty()) {
            cout << "A fila está vazia. Não é possível realizar peek()." << endl;
            return T();
        } else {
            return front->data;
        }
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void print() const {
        Node<T>* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Fila<int> fila;

    // Exemplo de uso
    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    fila.print(); // Deve imprimir: 10 20 30

    fila.dequeue();

    fila.print(); // Deve imprimir: 20 30

    cout << "Elemento na frente da fila: " << fila.peek() << endl; // Deve imprimir: 20

    return 0;
}
