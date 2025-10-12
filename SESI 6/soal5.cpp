/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 11 Oktober 2025
Deskripsi : faktorial
*/

#include <iostream>
using namespace std;

int inputBilangan(){
    int n;
    cout << "Masukkan nilangan untuk dihitung faktorialnya (Maks 256): ";
    cin >> n;
    return n;
}

long hitungFaktorial(int n){
    long hasil = 1;
    for(int i = 1; i <= n; i++){
        hasil *= i;
    }
    return hasil;
}

void cetakFaktorial(int n, long hasil){
    cout << "Faktorial dari " << n << " adalah: " << hasil << endl;
}

int main(){
    int n = inputBilangan();
    long hasil = hitungFaktorial(n);
    cetakFaktorial(n, hasil);
    return 0;
}