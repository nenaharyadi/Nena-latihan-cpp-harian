/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 29 September 2025
Deskripsi : menghitung rata-rata
*/

#include <iostream>
using namespace std;

void input(int &a, int &b, int &c){
    cout << "nilai a: ";
    cin >> a;
    cout << "nilai b: ";
    cin >> b;
    cout << "nilai c: ";
    cin >> c;
}
/*versi looping


*/

float rata_rata(int a, int b,int c){
    return (a+b+c)/3.0;
}

int main(){
    int a,b,c;
    float hasil;

    input(a,b,c);
    cout << "rata - rata :" << rata_rata(a,b,c);

    return 0;
}