/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 29 September 2025
Deskripsi : menghitung keliling lingkaran
*/

#include<iostream>
using namespace std;

void input(int &d){
    cout << "Masukkan diameter: ";
    cin >> d;
}

void keliling(int d, float &k){
    float phi = 3.14159;
    k = phi * d;
    cout << "Keliling lingkaran : " << k;
}

int main(){
    int d;
    float k;

    input(d);
    keliling(d,k);

    return 0;
}
