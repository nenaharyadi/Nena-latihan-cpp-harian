/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 29 September 2025
Deskripsi : menghitung tegangan
*/

#include <iostream>
using namespace std;

void input(int &A, int &T){
    cout << "Masukkan besar arus: ";
    cin >> A;
    cout << "Masukkan besar hambatan: ";
    cin >> T;
}

int hitung(int A, int T){
    return A * T;
}

int main(){
    int A,T, hasil;

    input(A,T);
    cout << "Tegangan = " << hitung(A,T);

    return 0;
}