/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 02 Oktober 2025
*/

#include <iostream>
using namespace std;

long getGajiBulanan(int tahun, int lamaKerja){
    if(lamaKerja < 0){
        cout << "Masa kerja tidak boleh negatif.";
        return 0;
    }

    if((tahun >= 2019)  && (tahun <= 2024)){
        switch(lamaKerja){
            case 0: case 1:
                return 2579400;
            case 2: case 3:
                return 2660700;
            case 4: case 5:
                return 2711500;
            case 6: case 7:
                return 2830900;
            case 8: case 9:
                return 2920100;
            default: return 0;
        }
    }
    else if(tahun >= 2024){
        switch(lamaKerja){
            case 0: case 1:
                return 2785700;
            case 2: case 3:
                return 2873500;
            case 4: case 5:
                return 2964000;
            case 6: case 7:
                return 3057300;
            case 8: case 9:
                return 3153600;
            default: return 0;
        }
    }
    else{
        return 0;
    }
}

int main(){
    int tahun, lamaKerja;

    cout << "Masukkan tahun : ";
    cin >> tahun;
    cout << "Masukkan masa bekerja (dalam tahun) : ";
    cin >> lamaKerja;

    long gajiBulanan = getGajiBulanan(tahun, lamaKerja);
    if(gajiBulanan > 0){
        cout << "Total gaji pokok tahun " << tahun << " = Rp " << gajiBulanan*12 << endl;
    }
    else{
        cout << "Error" << endl;
    }

    return 0;
}