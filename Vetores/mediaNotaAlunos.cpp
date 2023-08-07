#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int NUM_ALUNOS = 3;
    const int NUM_DISCIPLINAS = 2;
    vector<vector<double>> notas(NUM_ALUNOS, vector<double>(NUM_DISCIPLINAS));

    cout << "Digite as notas dos alunos nas duas disciplinas:\n";

    for (int i = 0; i < NUM_ALUNOS; ++i) {
        for (int j = 0; j < NUM_DISCIPLINAS; ++j) {
            cout << "Aluno " << i + 1 << ", Disciplina " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }

    cout << "\nMédia das notas de cada aluno:\n";

    for (int i = 0; i < NUM_ALUNOS; ++i) {
        double soma = 0.0;
        for (int j = 0; j < NUM_DISCIPLINAS; ++j) {
            soma += notas[i][j];
        }
        double media = soma / NUM_DISCIPLINAS;
        cout << "Aluno " << i + 1 << ": " << media << endl;
    }

    return 0;
}
