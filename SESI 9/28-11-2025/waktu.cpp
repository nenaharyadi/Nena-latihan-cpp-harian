/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 28 November 2025
Deskripsi : menghitung selisih waktu
Waktu pengerjaan : 25 menit
*/

#include<iostream>
using namespace std;

struct Waktu{
    int jam;
    int menit;
    int detik;
};

void inputWaktu(Waktu &wkt){
    do{
        cout << "Masukkan jam max 23:59:59" << endl;
        cout << "Masukkan jam = "; cin >> wkt.jam; 
        cout << "Masukkan menit = "; cin >> wkt.menit; 
        cout << "Masukkan detik = "; cin >> wkt.detik; 
        cout << "-------------------------------\n"; 
    } while (wkt.jam > 23 || wkt.menit > 59 || wkt.detik > 59);
}

void printWaktu(Waktu wkt) { 
    cout << wkt.jam << ":" << wkt.menit << ":" << wkt.detik; 
} 

void selisihWaktu(Waktu wktAkhir, Waktu wktAwal, Waktu& selisih) { 
    if(wktAkhir.detik < wktAwal.detik){ 
        wktAkhir.detik += 60; 
        wktAkhir.menit -= 1; 
        selisih.detik = wktAkhir.detik - wktAwal.detik;   
    } 
    else selisih.detik = wktAkhir.detik - wktAwal.detik; 
 
    if(wktAkhir.menit < wktAwal.menit){ 
        wktAkhir.menit += 60; 
        wktAkhir.jam -= 1; 
        selisih.menit = wktAkhir.menit - wktAwal.menit; 
    } 
    else selisih.menit = wktAkhir.menit - wktAwal.menit; 
 
    if(wktAkhir.jam < wktAwal.jam){ 
        wktAkhir.jam += 24; 
        selisih.jam = wktAkhir.jam - wktAwal.jam; 
    } 
    else selisih.jam = wktAkhir.jam - wktAwal.jam; 
}

int main(){ 
    Waktu wktAkhir, wktAwal, selisih; 
    cout << "Input waktu awal\n"; 
    inputWaktu(wktAwal); 
    cout << "\nInput waktu akhir\n"; 
    inputWaktu(wktAkhir); 
    selisihWaktu(wktAkhir, wktAwal, selisih); 
    cout << "\n-------------Hasil-------------"; 
    cout << "\nWaktu awal : "; printWaktu(wktAwal); 
    cout << "\nWaktu akhir : "; printWaktu(wktAkhir); 
    cout << "\nSelisih waktu : "; printWaktu(selisih); 
} 
