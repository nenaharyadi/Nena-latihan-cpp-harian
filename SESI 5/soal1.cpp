/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 3 Oktober 2025
Deskripsi : menghitung rata rata perubahan suhu setiap jam
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int suhu, totalSuhu = 0;
    int jmlJam = 24;

    for(int jam = 1; jam <= jmlJam; jam++){
        cout << "Masukkan suhu badan ke-" << jam << " : ";
        cin >> suhu;
        totalSuhu += suhu;
    }

    float rataSuhu = float(totalSuhu) / jmlJam;

    cout << "Rata-rata suhu selama " << jmlJam << " jam adalah " << rataSuhu << endl;

    system("pause");
    return 0;
}
