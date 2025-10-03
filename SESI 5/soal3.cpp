/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 3 Oktober 2025
Deskripsi : cek kata palindrom
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string kata;
    cout << "Masukkan kata : ";
    cin >> kata;

    bool palindrom = true;
    int n = kata.length();
    for(int i = 0; i < n/2; i++){
        if(kata[i] != kata[n-i-1]){
            palindrom = false;
            break;
        }
    }

    if(palindrom){
        cout << kata << " adalah palindrom" << endl;
    }
    else{
        cout << kata << " bukan palindrom" << endl;
    }
    return 0;
}