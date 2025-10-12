/*
Nama     : Nena Haryadi Puspanegara
NPM      : 140810240034
Tanggal  : 12 Oktober 2025
Deskripsi: Program menyimpan dan mengolah nilai mahasiswa
*/

#include <iostream>
using namespace std;

void inputNilai(int nilai[], int &jumlah){
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cout << endl;

    for(int i = 0; i < jumlah; i++){
        cout << "Nilai mahasiswa ke-" << i + 1 << " : ";
        cin >> nilai[i];
    }
}

void cetakNilai(int nilai[], int jumlah){
    cout << "Daftar nilai mahasiswa: ";
    for(int i = 0; i < jumlah; i++){
        cout << nilai[i] << " ";
    }
    cout << endl;
}

float hitungRataRata(int nilai[], int jumlah){
    int total = 0;
    for(int i = 0; i < jumlah; i++){
        total += nilai[i];
    }
    return (float) total / jumlah;
}

void cariMaxMin(int nilai[], int jumlah, int &max, int &min){
    max = nilai[0];
    min = nilai[0];

    for(int i = 1; i < jumlah; i++){
        if(nilai[i] > max){
            max = nilai[i];
        }
        if(nilai[i] < min){
            min = nilai[i];
        }
    } 
}

void cariTinggiRendah(int nilai[], int jumlah, int max, int min){
    cout << "Mahasiswa dengan nilai tertinggi (" << max << "): ";
    for(int i = 0; i < jumlah; i++){
        if(nilai[i] == max){
            cout << "Mahasiswa ke-" << i + 1 << " ";
        }
    }

    cout << "\nMahasiswa dengan nilai terrendah (" << min << "): ";
    for(int i = 0; i < jumlah; i++){
        if(nilai[i] == min){
            cout << "Mahasiswa ke-" << i + 1 << " ";
        }
    }
    cout << endl;
}

int main(){
    int nilai[100];
    int jumlah, max, min;

    inputNilai(nilai, jumlah);
    cetakNilai(nilai, jumlah);

    float rata = hitungRataRata(nilai, jumlah);
    cout << "\nRata - rata nilai: " << rata << endl;

    cariMaxMin(nilai, jumlah, max, min);
    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum : " << min << endl;

    cariTinggiRendah(nilai, jumlah, max, min);
    return 0;
}