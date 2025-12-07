/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 3 Desember 2025
Deskripsi : hitung rata rata mahasiswa dengan pointer
Waktu pengerjaan : 30 menit
*/

#include <iostream>
using namespace std;

float hitungRata(int *nilai, int jumlah) {
    int total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += *(nilai + i);
    }
    return (float) total / jumlah;
}

int main() {
    int jumlah;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    int *nilai = new int[jumlah];
    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> *(nilai + i);
    }

    cout << "\nDaftar Nilai Mahasiswa:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << ": " << *(nilai + i) << endl;
    }

    float rata = hitungRata(nilai, jumlah);
    cout << "\nRata-rata nilai: " << rata << endl;

    delete[] nilai;
    return 0;
}
