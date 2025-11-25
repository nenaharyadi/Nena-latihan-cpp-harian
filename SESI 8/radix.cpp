#include <iostream>
using namespace std;

int getDigit(int num, int digitPlace) {
    // Contoh: getDigit(173, 10) -> (173 / 10) % 10 -> 17 % 10 -> 7
    return (num / digitPlace) % 10;
}

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSort(int arr[], int n, int digitPlace) {
    
    // 1. Siapkan array output dan array 'count' (keranjang 0-9)
    int output[n];
    int count[10] = {0}; // Inisialisasi semua keranjang ke 0

    // 2. Hitung frekuensi setiap digit (0-9)
    //    Masukkan ke keranjang 'count'
    for (int i = 0; i < n; i++) {
        int digit = getDigit(arr[i], digitPlace);
        count[digit]++;
    }

    // 3. Akumulasi 'count'
    //    Ubah 'count[i]' agar berisi posisi akhir dari digit 'i' di array output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build array output
    //    Loop MUNDUR (dari n-1) untuk menjaga stabilitas
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], digitPlace);
        
        // Letakkan angka di posisi yang tepat di 'output'
        // count[digit] - 1 adalah indeks yang benar
        output[count[digit] - 1] = arr[i];
        
        // Kurangi 'jatah' di keranjang count
        count[digit]--;
    }

    // 5. Salin array 'output' yang sudah terurut kembali ke 'arr'
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    // 1. Cari nilai maksimum untuk tahu jumlah digit
    int maxVal = getMax(arr, n);

    // 2. Lakukan counting sort untuk setiap digit,
    //    mulai dari satuan (1), lalu puluhan (10), ratusan (100), dst.
    for (int digitPlace = 1; maxVal / digitPlace > 0; digitPlace *= 10) {
        countingSort(arr, n, digitPlace);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100]; // Array statis (maks 100 elemen)
    int n = 0;    // Penghitung jumlah elemen yang diinput

    cout << "Masukkan elemen (pisahkan dengan spasi, akhiri dengan -1): ";
    
    // Loop untuk mengambil input
    while (true) {
        int number;
        cin >> number;
        if (number == -1) break; // Berhenti jika user input -1
        
        arr[n++] = number; // Masukkan angka ke array dan increment n
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    // Panggil fungsi sort
    radixSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);
    
    return 0;
}