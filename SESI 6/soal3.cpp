/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 10 Oktober 2025
Deskripsi : cek kata palindrom
*/

#include <iostream>
using namespace std;

string inputKata(){
    string kata;
    cout << "Masukkan kata (max 255 karakter): ";
    cin >> kata;
    return kata;
}

bool isPalindrom(string kata){
    int n = kata.length();
    for(int i = 0; i < n/2; i++){
        if(kata[i] != kata[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string kata = inputKata();
    bool cetak = isPalindrom(kata);

    if(cetak){
        cout << kata << " adalah palindrom." << endl;
    }
    else{
        cout << kata << " bukan palindrom." << endl;
    }

    return 0;
}