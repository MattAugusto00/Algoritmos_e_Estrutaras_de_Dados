#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool troca;

    for (int i = 0; i < n - 1; ++i) {
        troca = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                troca = true;
            }
        }

        // Se não houve troca nesta iteração, o vetor já está ordenado
        if (!troca) {
            break;
        }
    }
}

int main() {
    vector<int> vetor = {64, 34, 25, 12, 22, 11, 90};
    cout << "Vetor original: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    bubbleSort(vetor);

    cout << "Vetor ordenado: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
