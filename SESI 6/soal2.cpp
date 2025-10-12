/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 10 Oktober 2025
Deskripsi : segitiga pascal
*/

#include <iostream>
using namespace std;

int inputJumlahBaris(){
    int n;
    cout << "Masukkan jumlah baris : ";
    cin >> n;
    return n;
}

void cetakSegitigaPascal(int n){
    for(int i = 0; i < n; i++){
        int angka = 1;
        for(int spasi = 0; spasi < n-i-1; spasi++){
            cout << " ";
        }
        for(int j = 0; j <= i; j++){
            cout << angka << " ";
            angka = angka *  (i - j)/(j + 1);
        }
        cout << endl;
    }
}

int main(){
    int n = inputJumlahBaris();
    cetakSegitigaPascal(n);
    return 0;
}

