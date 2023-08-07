#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int numeroAleatorio = rand() % 100 + 1;
    int palpite, tentativas = 0;

    cout << "Bem-vindo ao jogo de adivinhacao!\n";
    cout << "Tente adivinhar o numero entre 1 e 100.\n";

    do {
        cout << "Digite seu palpite: ";
        cin >> palpite;
        tentativas++;

        if (palpite < numeroAleatorio) {
            cout << "Chutou abaixo! Tente novamente.\n";
        } else if (palpite > numeroAleatorio) {
            cout << "Chutou acima! Tente novamente.\n";
        } else {
            cout << "Parabens! Voce acertou o numero em " << tentativas << " tentativas!\n";
        }
    } while (palpite != numeroAleatorio);

    return 0;
}
