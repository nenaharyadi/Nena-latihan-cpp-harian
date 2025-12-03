#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string npm;
    string nama;
    int nilaiTugas;
    int nilaiKuis;
    int nilaiUTS;
    int nilaiUAS;
};

typedef Mahasiswa dataMhs[10];
dataMhs mhsTI;

void banyakData(int& n){
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;
}

void inputMahasiswa(dataMhs& mhsTI, int n){
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "==== Data mahasiswa ke-" << i +1 << " ====" << endl;
        cout << "NPM    : ";
        getline(cin, mhsTI[i].npm);
        cout << "Nama   : ";
        getline(cin, mhsTI[i].nama);
        cout << "Nilai Tugas: ";
        cin >> mhsTI[i].nilaiTugas;
        cout << "Nilai Kuis: ";
        cin >> mhsTI[i].nilaiKuis;
        cout << "Nilai UTS: ";
        cin >> mhsTI[i].nilaiUTS;
        cout << "Nilai UAS: ";
        cin >> mhsTI[i].nilaiUAS;
        cin.ignore();
        cout << endl;
    }
}

float nilaiAkhir(Mahasiswa dataMhs){
    return (dataMhs.nilaiTugas + dataMhs.nilaiKuis + dataMhs.nilaiUTS + dataMhs.nilaiUAS) / 4.0;
}

void tukar(Mahasiswa& a, Mahasiswa& b){
    Mahasiswa temp = a;
    a = b;
    b = temp;
}

void descendingSort(dataMhs& mhsTI, int n){
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if (nilaiAkhir(mhsTI[j]) < nilaiAkhir(mhsTI[j+1])){
                tukar(mhsTI[j], mhsTI[j+1]);
            }
        }
    }
}

void salinLarik(dataMhs mhsTI, dataMhs& mhsTISalin, int n){
    for (int i = 0; i < n; i++){
        mhsTISalin[i] = mhsTI[i];
    }
}

char hurufMutu(float nilai){
    if (nilai >= 80 && nilai <= 100){
        return 'A';
    }
    else if (nilai >= 68 && nilai < 80){
        return 'B';
    }
    else if (nilai >= 55 && nilai < 68){
        return 'C';
    }
    else{
        return 'D';
    }
}

string status(float nilai) {
    if(nilai >= 68){
        return "Lulus";
    }
    else{
        return "Tidak Lulus";
    }
}

void cetak(dataMhs mhsTI, int n){
    cout << left;
    cout << setw(4) << "No"
         << setw(15) << "NPM"
         << setw(25) << "Nama"
         << setw(10) << "Tugas"
         << setw(10) << "Kuis"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(15) << "Nilai Akhir"
         << setw(10) << "Huruf"
         << "Status" << endl;

    for(int i = 0;i < n; i++){
        cout << setw(4) << i + 1
             << setw(15) << mhsTI[i].npm
             << setw(25) << mhsTI[i].nama
             << setw(10) << mhsTI[i].nilaiTugas
             << setw(10) << mhsTI[i].nilaiKuis
             << setw(10) << mhsTI[i].nilaiUTS
             << setw(10) << mhsTI[i].nilaiUAS
             << setw(15) << fixed << setprecision(2) << nilaiAkhir(mhsTI[i])
             << setw(10) << hurufMutu(nilaiAkhir(mhsTI[i]))
             << status(nilaiAkhir(mhsTI[i])) << endl;
    }
}

float rataNilaiAkhir(dataMhs mhsTI, int n){
    float jumlah = 0;
    for(int i = 0; i < n; i++){
        jumlah += nilaiAkhir(mhsTI[i]);
    }
    return jumlah/n;
}

float nilaiTertinggi(dataMhs mhsTI, int n){
    float terbesar = nilaiAkhir(mhsTI[0]);
    for(int i = 0; i < n; i++){
        if(nilaiAkhir(mhsTI[i]) > terbesar){
            terbesar = nilaiAkhir(mhsTI[i]);
        }
    }
    return terbesar;
}

float nilaiTerendah(dataMhs mhsTI, int n){
    float terendah = nilaiAkhir(mhsTI[0]);
    for(int i = 0; i < n; i++){
        if(nilaiAkhir(mhsTI[i]) < terendah){
            terendah = nilaiAkhir(mhsTI[i]);
        }
    }
    return terendah;
}

void menu(dataMhs mhsTI, int n){
    int pilih;
    string yesOrNo;
    dataMhs mhsTISort;
    do{
        cout << "================ MENU ================" << endl;
        cout << "1.Tampilkan tabel data mahasiswa." << endl;
        cout << "2.Tampilkan nilai rata-rata." << endl;
        cout << "3.Tampilkan nilai tertinggi." << endl;
        cout << "4.Tampilkan nilai terendah." << endl;
        cout << "5.Tampilkan tabel berdasar urutan nilai akhir." << endl;
        cout << "Pilih (1-5): ";
        cin >> pilih;
        cout << endl;

        switch(pilih){
            case 1:
                cetak(mhsTI,n);
                cout << endl;
            break;

            case 2:
                cout << "Rata-rata nilai akhir: " << rataNilaiAkhir(mhsTI,n);
                cout << endl;
            break;

            case 3:
                cout << "Nilai tertinggi: " << nilaiTertinggi(mhsTI,n);
                cout << endl;
            break;

            case 4:
                cout << "Nilai terendah: " << nilaiTerendah(mhsTI,n);
                cout << endl;
            break;

            case 5:
                salinLarik(mhsTI, mhsTISort, n);
                descendingSort(mhsTISort, n);
                cetak(mhsTISort, n);
            break;

            default:
                cout << "Pilihan tidak valid" << endl;
        }
        do {
            cout << "Apakah ingin melanjutkan? (y/n): ";
            cin >> yesOrNo;

            if(!yesOrNo.empty()){
                yesOrNo[0] = toupper(yesOrNo[0]);
            }

            if(yesOrNo != "Y" && yesOrNo != "N"){
                cout << "Input tidak valid! Masukkan hanya 'y' atau 'n'." << endl;
            }
        }
        while (yesOrNo != "Y" && yesOrNo != "N");
    }
    while (yesOrNo != "N");
    cout << "Program Selesai!";
}

int main(){
    dataMhs mhsTI;
    int n;
    banyakData(n);
    inputMahasiswa(mhsTI, n);
    cout << endl;
    menu(mhsTI, n);
}