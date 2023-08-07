#include <iostream>
#include <list>
#include <vector>
using namespace std;


template<typename K, typename V>
class HashTable {
private:
    vector<list<pair<K, V>>> table;
    int capacity;
    int size;

    int hashFunction(const K& key) const {
        hash<K> hashFunction;
        return hashFunction(key) % capacity;
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity);
    }

    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }

        table[index].emplace_back(key, value);
        size++;
    }

    V get(const K& key) const {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }

        throw out_of_range("Chave nao encontrada na tabela hash.");
    }

    void remove(const K& key) {
        int index = hashFunction(key);
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it);
                size--;
                return;
            }
        }
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    HashTable<string, int> tabelaHash(10);

    // Exemplo de uso
    tabelaHash.insert("chave1", 10);
    tabelaHash.insert("chave2", 20);
    tabelaHash.insert("chave3", 30);

    cout << "Tamanho da tabela hash: " << tabelaHash.getSize() << endl; // Deve imprimir: 3

    cout << "Valor da chave 'chave2': " << tabelaHash.get("chave2") << endl; // Deve imprimir: 20

    tabelaHash.remove("chave1");
    cout << "Tamanho apos remover 'chave1': " << tabelaHash.getSize() << endl; // Deve imprimir: 2

    return 0;
}
