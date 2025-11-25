#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Fungsi Counting Sort (mendukung angka negatif juga)
void countingSort(int arr[], int n) {
    // cari nilai minimum dan maksimum dalam array
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int range = maxVal - minVal + 1; // total rentang nilai yang muncul

    // 2buat array count dan output
    int* count = new int[range] {0};
    int* output = new int[n];

    // hitung frekuensi setiap elemen (digeser biar mulai dari 0)
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    // ubah count[i] jadi posisi kumulatif
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // susun elemen ke output secara stabil (mundur dari belakang)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // hasil dari output ke array asli
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Hapus memori sementara
    delete[] count;
    delete[] output;
}

int main() {
    int arr[100];
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan " << n << " elemen (boleh negatif): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray sebelum diurutkan: ";
    printArray(arr, n);

    /*cout << "\n=== Proses Counting Sort ===\n";
    countingSort(arr, n);*/

    cout << "\nArray setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}