#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
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

    selectionSort(vetor);

    cout << "Vetor ordenado: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
