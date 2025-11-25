//linear search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 1; i <= n; i++) {
        if (arr[i] == key) {
            return i; // ketemu
        }
    }
    return -1; // tidak ditemukan
}

int main() {
    int arr[100], n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan elemen array: ";
    for (int i = 1; i <= n; i++) { // <-- diperbaiki
        cin >> arr[i];
    }

    int key;
    cout << "Masukkan nilai yang dicari: ";
    cin >> key;

    int hasil = linearSearch(arr, n, key);

    if (hasil != -1)
        cout << "Elemen ditemukan pada indeks: " << hasil << endl;
    else
        cout << "Elemen TIDAK ditemukan" << endl;

    return 0;
}