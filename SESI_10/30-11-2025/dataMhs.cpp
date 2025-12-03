/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 30 November 2025
Deskripsi : data mahasiswa
Waktu pengerjaan : 35 menit
*/

#include <iostream>
using namespace std;

struct Mahasiswa {
    char npm[12];       
    string nama;     
    int nilai;         
};

typedef Mahasiswa LarikMhs[10];

void banyakData(int& n) {
    cout << "Banyak data: ";
    cin >> n;
}

void inputMahasiswa(LarikMhs& mhs, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukan data mahasiswa ke-" << (i + 1) << endl;
        cout << "NPM    : ";
        cin >> mhs[i].npm;
        cin.ignore();
        cout << "Nama   : ";
        cin >> mhs[i].nama;
        cout << "Nilai  : ";
        cin >> mhs[i].nilai;
    }
}

void cetakMahasiswa(LarikMhs mhs, int n) {
    cout << "PENCETAKAN DATA MAHASISWA" << endl;
    for (int i = 0; i < n; i++) {
        cout << "NPM: " << mhs[i].npm 
             << ", Nama: " << mhs[i].nama 
             << ", Nilai: " << mhs[i].nilai << endl;
    }
}

float rata_rata(LarikMhs a, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i].nilai;
    }
    return total / n;
}

float nilaiTertinggi(LarikMhs a, int n) {
    float terbesar = a[0].nilai;
    for (int i = 1; i < n; i++) {
        if (a[i].nilai > terbesar) {
            terbesar = a[i].nilai;
        }
    }
    return terbesar;
}

void swap(Mahasiswa& a, Mahasiswa& b) {
    Mahasiswa temp = a;
    a = b;
    b = temp;
}

int bandingkanChar(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) return -1; 
        if (s1[i] > s2[i]) return 1; 
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;   
    if (s1[i] == '\0') return -1;                   
    return 1;                                       
}

void ascendingSort(LarikMhs a, int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (bandingkanChar(a[j].npm, a[j + 1].npm) > 0) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    LarikMhs mhs;
    int n;

    banyakData(n);
    inputMahasiswa(mhs, n);
    cout << "\nData Mahasiswa Sebelum Pengurutan:\n";
    cetakMahasiswa(mhs, n);

    float avg = rata_rata(mhs, n);
    cout << "Rata-rata Nilai Mahasiswa: " << avg << endl;

    float nilai_tertinggi = nilaiTertinggi(mhs, n);
    cout << "Nilai Tertinggi Mahasiswa: " << nilai_tertinggi << endl;
    ascendingSort(mhs, n);

    cout << "Data Mahasiswa Setelah Pengurutan Berdasarkan NPM: " << endl;
    cetakMahasiswa(mhs, n);

    return 0;
}