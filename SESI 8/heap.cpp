#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Fungsi heapify: memastikan subtree dengan root di indeks i memenuhi sifat max-heap
void heapify(int arr[], int n, int i) {
    int largest = i;       // Inisialisasi node terbesar sebagai root
    int left = 2 * i + 1;  // Indeks anak kiri
    int right = 2 * i + 2; // Indeks anak kanan

    // Jika anak kiri lebih besar dari root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Jika anak kanan lebih besar dari node terbesar sebelumnya
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Jika root bukan yang terbesar, tukar dan lanjutkan heapify rekursif
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Fungsi utama untuk melakukan heap sort
void heapSort(int arr[], int n) {
    // Langkah 1: Bangun max heap dari array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "\nHeap awal (setelah dibangun): ";
    printArray(arr, n);

    // Langkah 2: Ekstrak elemen satu per satu dari heap
    for (int i = n - 1; i > 0; i--) {
        // Pindahkan elemen root (terbesar) ke akhir array
        swap(arr[0], arr[i]);

        cout << "Setelah memindahkan elemen terbesar ke posisi " << i << ": ";
        printArray(arr, n);

        // Panggil heapify pada heap yang tersisa
        heapify(arr, i, 0);
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

    cout << "\n=== Proses Heap Sort ===\n";
    heapSort(arr, n);

    cout << "\nArray setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}