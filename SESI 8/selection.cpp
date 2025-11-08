#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // asumsikan elemen ke-i adalah yang terkecil

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // simpan indeks elemen terkecil
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // cetak elemen dengan spasi
    }
    cout << endl;
}

int main() {
    int arr[100];
    int n = 0; 

    cout << "Masukkan elemen (akhiri dengan -1): ";

    while (true){
        int number;
        cin >> number; // baca angka dari input

        if (number == -1)
            break;

        arr[n++] = number; 
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);
    selectionSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    return 0; 
}