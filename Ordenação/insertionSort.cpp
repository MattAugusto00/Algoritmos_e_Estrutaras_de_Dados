#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}

int main() {
    vector<int> vetor = {64, 34, 25, 12, 22, 11, 90};
    cout << "Vetor original: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(vetor);

    cout << "Vetor ordenado: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
