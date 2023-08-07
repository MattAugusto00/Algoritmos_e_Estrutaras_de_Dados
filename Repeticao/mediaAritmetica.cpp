#include <iostream>

using namespace std;

int main() {
    int quantidadeNumeros;
    double numero, soma = 0.0;

    cout << "Calculadora de media aritmetica\n";
    cout << "Quantos numeros voce deseja calcular a media? ";
    cin >> quantidadeNumeros;

    for (int i = 1; i <= quantidadeNumeros; ++i) {
        cout << "Insira o " << i << "o numero: ";
        cin >> numero;
        soma += numero;
    }

    double media = soma / quantidadeNumeros;
    cout << "A media aritmetica dos numeros inseridos e: " << media << endl;

    return 0;
}
