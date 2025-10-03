/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 3 Oktober 2025
Deskripsi : segitiga pascal
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Masukkan jumlah baris : ";
    cin >> n;

    for(int i = 0; i < n; i++){
        int angka = 1;

        for(int spasi = 0; spasi < n - i - 1; spasi++){
            cout << " ";
        }

        for(int j = 0; j <= i; j++){
            cout << angka << " ";
            angka = angka * (i - j) / (j + 1); 
        }

        cout << endl;
    }
    return 0;
}