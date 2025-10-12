/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 6 Oktober 2025
Deskripsi : menghitung rata rata perubahan suhu setiap jam
*/

#include <iostream>
using namespace std;

void inputSuhuBadan(int jmlJam, int &suhuTotal){
    int suhu;
    suhuTotal = 0;

    for(int jam = 1; jam <= jmlJam; jam++){
        cout << "Masukkan suhu badan ke-" << jam << " : ";
        cin >> suhu;
        suhuTotal += suhu;
    }
}

float hitungRataRata(int suhuTotal, int jmlJam){
    return (float)suhuTotal / jmlJam;
}

void cetak(int jmlJam, float rataRata){
    cout << "Rata-rata suhu selama " << jmlJam 
         << " jam adalah " << rataRata << " derajat." << endl;
}

int main(){
    int suhuTotal;
    int jmlJam = 24;
    float rataRata;

    inputSuhuBadan(jmlJam, suhuTotal);
    rataRata = hitungRataRata(suhuTotal, jmlJam);
    cetak(jmlJam, rataRata);

    return 0;
}
