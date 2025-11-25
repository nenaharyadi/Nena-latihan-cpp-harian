#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fungsi partition: memposisikan pivot di tempat yang benar
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // elemen terakhir jadi pivot
    int i = low - 1;

    cout << "\nPivot: " << pivot << endl;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "Array setelah partition (low=" << low << ", high=" << high << "): ";
    printArray(arr, high + 1);

    return i + 1;
}

// Fungsi Quick Sort rekursif
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Rekursif untuk bagian kiri dan kanan pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[100];
    int n;

    /*cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan " << n << " elemen (boleh termasuk -1): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }*/

    cout << "Masukkan elemen (akhiri dengan -1): ";
    while (true){
        int number;
        cin >> number;
        if (number == -1) break; // berhenti jika input -1
        arr[n++] = number;
    }

    cout << "\nArray sebelum diurutkan: ";
    printArray(arr, n);

    cout << "\n=== Proses Quick Sort ===\n";
    quickSort(arr, 0, n - 1);

    cout << "\nArray setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}