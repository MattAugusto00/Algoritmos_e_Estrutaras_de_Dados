#include <iostream>
#include <vector>

using namespace std;

int main() {
    int quantidadeNumeros;
    cout << "Encontre o maior e o menor numero\n";
    cout << "Quantos numeros voce deseja comparar? ";
    cin >> quantidadeNumeros;

    vector<int> numeros;

    for (int i = 1; i <= quantidadeNumeros; ++i) {
        int numero;
        cout << "Insira o " << i << "o numero: ";
        cin >> numero;
        numeros.push_back(numero);
    }

    int maior = numeros[0];
    int menor = numeros[0];

    for (int i = 1; i < numeros.size(); i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    cout << "O maior numero e: " << maior << endl;
    cout << "O menor numero e: " << menor << endl;

    return 0;
}
