/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 28 November 2025
Deskripsi : menghitung titik tengah dan menentukan hasil pencerminan nya
Waktu pengerjaan : 25 menit
*/

#include <iostream>
using namespace std;

struct Koordinat{
    float absis;
    float ordinat;
};

void inputTitik(Koordinat &titik){
    cout << "Masukkan absis: ";
    cin >> titik.absis;
    cout << "Masukkan ordinat: ";
    cin >> titik.ordinat;
}

void printTitik(Koordinat titik){
    cout << "(" << titik.absis << "," << titik.ordinat << ")";
}

Koordinat titikTengah(Koordinat a, Koordinat b){
    Koordinat tengah;
    tengah.absis = (a.absis + b.absis)/2;
    tengah.ordinat = (a.ordinat + b.ordinat)/2;
    return tengah;
}

Koordinat percerminanX(Koordinat a, Koordinat b, Koordinat t){ 
    Koordinat cermin; 
    t = titikTengah(a,b); 
    cout << "======== Dicerminkan terhadap sumbu X ========" << endl; 
    cermin.ordinat = -(a.ordinat); 
    cout << "Hasil Percerminan titik A: (" << a.absis << "," << cermin.ordinat << ")" << endl; 
    cermin.ordinat = -(b.ordinat); 
    cout << "Hasil Percerminan titik B: (" << b.absis << "," << cermin.ordinat << ")" << endl; 
    cermin.ordinat = -(t.ordinat); 
    cout << "Hasil Percerminan titik tengah: (" << t.absis << "," << cermin.ordinat << ")" << endl; 
    return cermin; 
} 

Koordinat percerminanY(Koordinat a,Koordinat b, Koordinat t){ 
    Koordinat cermin; 
    t = titikTengah(a,b); 
    cout << "======== Dicerminkan terhadap sumbu Y ========" << endl; 
    cermin.absis = -(a.absis); 
    cout << "Hasil Percerminan titik A: (" << cermin.absis << "," << a.ordinat << ")" << endl; 
    cermin.absis = -(b.absis); 
    cout << "Hasil Percerminan titik B: (" << cermin.absis << "," << b.ordinat << ")" << endl; 
    cermin.absis = -(t.absis); 
    cout << "Hasil Percerminan titik tengah: (" << cermin.absis << "," << t.ordinat << ")" << endl; 
    return cermin; 
} 

void menu(Koordinat a, Koordinat b){
    Koordinat t, hasil, cermin;
    int pilih;
    char yesOrNo;

    do{
        cout << "==================== MENU ====================" << endl; 
        cout << "1. Menentukan titik tengah " << endl;
        cout << "2. Percerminan terhadap sumbu X" << endl;
        cout << "3. Percerminan terhadap sumbu Y" << endl; 
        cout << "Pilih opsi (1-3): "; 
        cin >> pilih; 
        cout << endl; 

        switch(pilih){
            case 1:{ 
                Koordinat tengah = titikTengah(a,b); 
                cout << "================ Titik Tengah ================"<< endl; 
                cout << "Titik tengah: (" << tengah.absis << "," << tengah.ordinat << ")" << endl; 
                cout << endl; 
                break; 
            }
            case 2:{
                Koordinat cermin = percerminanX(a,b,t); 
                cout << endl; 
                break; 
            }
            case 3:{
                Koordinat cermin = percerminanY(a,b,t);
                cout << endl; 
                break; 
            }

        } 
        do{
            cout <<"Apakah ingin melanjutkan? (y/n) : "; 
            cin >> yesOrNo; 
            cout << endl; 
            if (toupper(yesOrNo) != 'Y' && toupper(yesOrNo) != 'N') { 
                cout << "Hanya input (y/n)\n"; 
            } 
        } 
        while (toupper(yesOrNo) != 'Y' && toupper(yesOrNo) != 'N');
    }  
    while(toupper(yesOrNo) != 'N');
    cout << "Program Selesai";
}

int main(){ 
    cout << "Masukkan absis dan ordinat dari titik tersebut!" << endl; 
    Koordinat a,b; 
 
    cout << "Masukkan titik A:" << endl; 
    inputTitik(a); 
    printTitik(a); cout << endl; 
    cout << "Masukkan titik B:" << endl; 
    inputTitik(b); 
    printTitik(b);cout << endl; 
 
    menu(a,b); 
 
    return 0; 
} 