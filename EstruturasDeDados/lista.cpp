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
class Lista {
private:
    No<T>* head;
    int size;

public:
    Lista() : head(nullptr), size(0) {}

    ~Lista() {
        clear();
    }

    void pushFront(T data) {
        No<T>* newNo = new No<T>(data);
        if (isEmpty()) {
            head = newNo;
        } else {
            newNo->next = head;
            head = newNo;
        }
        size++;
    }

    void pushBack(T data) {
        No<T>* newNo = new No<T>(data);
        if (isEmpty()) {
            head = newNo;
        } else {
            No<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNo;
        }
        size++;
    }

    void popFront() {
        if (isEmpty()) {
            cout << "A lista está vazia. Não é possível realizar popFront()." << endl;
        } else {
            No<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void popBack() {
        if (isEmpty()) {
            cout << "A lista está vazia. Não é possível realizar popBack()." << endl;
        } else if (size == 1) {
            delete head;
            head = nullptr;
            size--;
        } else {
            No<T>* current = head;
            No<T>* previous = nullptr;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            delete current;
            previous->next = nullptr;
            size--;
        }
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    void print() const {
        No<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Lista<int> lista;

    // Exemplo de uso
    lista.pushBack(10);
    lista.pushBack(20);
    lista.pushFront(5);
    lista.pushBack(30);

    lista.print(); // Deve imprimir: 5 10 20 30

    lista.popFront();
    lista.popBack();

    lista.print(); // Deve imprimir: 10 20

    return 0;
}
