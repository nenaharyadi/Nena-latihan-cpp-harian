/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 3 Oktober 2025
Deskripsi : faktorial
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    long faktorial = 1;

    cout << "Masukkan angka : ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        faktorial *= i;
    }

    cout << n << "!= " << faktorial << endl;
    return 0;
}