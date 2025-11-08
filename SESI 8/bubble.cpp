#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false; 

        for (int j = 0; j < n - i - 1; j++){
            // Jika elemen sekarang lebih besar dari elemen setelahnya, tukar posisi
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // tandai bahwa terjadi pertukaran
            }
        }

        if (!swapped)
            break;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int main() {
    int arr[100]; 
    int n = 0; 

    cout << "Masukkan elemen (akhiri dengan -1): ";

    while (true){
        int number;
        cin >> number;

        if (number == -1) // jika input adalah -1, berhenti membaca input
            break;

        arr[n++] = number; 
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);
    bubbleSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}
