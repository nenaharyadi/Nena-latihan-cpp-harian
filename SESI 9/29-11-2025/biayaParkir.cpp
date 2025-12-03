/*
Nama : Nena Haryadi Puspanegara
NPM  : 140810240034
Tanggal : 29 November 2025
Deskripsi : menghitung biaya parkir
Waktu pengerjaan : 35 menit
*/

#include <iostream> 
using namespace std; 
 
struct Time { 
    int jam; 
    int menit; 
    int detik; 
}; 
 
int konversiDetik(Time waktu) { 
    return waktu.jam * 3600 + waktu.menit * 60 + waktu.detik; 
} 

void selisihWaktu(Time datang, Time pulang, int& detikDatang, int& 
detikPulang, int& selisih) { 
    if (pulang.jam < datang.jam) { 
        pulang.jam = pulang.jam + 24; 
    } 
     
    detikDatang = konversiDetik(datang); 
    detikPulang = konversiDetik(pulang); 
     
    selisih = detikPulang - detikDatang; 
} 
 
void konversiWaktu(int selisih, Time& durasi) { 
    int sisa; 
    durasi.jam = selisih / 3600; 
    sisa = selisih % 3600; 
    durasi.menit = sisa / 60; 
    durasi.detik = sisa % 60; 
} 

void jumlahBayar(int selisih, int& bayar, Time &durasi, string tipe) { 
    konversiWaktu(selisih, durasi); 
    if (durasi.menit <= 5 && durasi.jam < 1) { 
        bayar = 0; 
    } else { 
        if (tipe == "mobil" || tipe == "Mobil" || tipe == "MOBIL") { 
            if (durasi.menit > 0 || durasi.detik > 0) { 
                bayar = durasi.jam * 3000 + 3000; 
            } else { 
                bayar = durasi.jam * 3000;
             } 
        } else { 
            if (durasi.menit > 0 || durasi.detik > 0) { 
                bayar = durasi.jam * 2000 + 2000; 
            } else { 
                bayar = durasi.jam * 2000; 
            } 
        } 
    } 
}

int main() { 
    Time datang, pulang, durasi; 
    int valid; 
    int detikDatang, detikPulang, selisih = 0; 
    int bayar; 
    string tipe; 
     
    do { 
        valid = 1; 
        cout << "Masukkan tipe kendaraan Anda (ketik mobil/motor): "; 
        cin >> tipe; 
        cout << "Masukkan jam datang: "; 
        cin >> datang.jam; 
        cout << "Masukkan menit datang: "; 
        cin >> datang.menit; 
        cout << "Masukkan detik datang: "; 
        cin >> datang.detik; 
        cout << "-----------------------------------\n"; 
        cout << "Masukkan jam pulang: "; 
        cin >> pulang.jam; 
        cout << "Masukkan menit pulang: "; 
        cin >> pulang.menit; 
        cout << "Masukkan detik pulang: "; 
        cin >> pulang.detik; 
        if (datang.jam < 0 || datang.jam > 23 || datang.menit < 0 || datang.menit > 59 || datang.detik < 0 || datang.detik > 59 || 
            pulang.jam < 0 || pulang.jam > 23 || pulang.menit < 0 || pulang.menit > 59 || pulang.detik < 0 || pulang.detik > 59) { 
            cout << "-----------------------------------\n"; 
            cout << "Inputan jam tidak valid. Silahkan masukkan lagi waktu menggunakan angka yang valid.\n"; 
            cout << "-----------------------------------\n"; 
            valid = 0; 
        }
        if (tipe != "mobil" && tipe != "Mobil" && tipe != "MOBIL" && tipe != "motor" && tipe != "Motor" && tipe != "MOTOR"){ 
            cout << "-----------------------------------\n"; 
            cout << "Tipe kendaraan tidak valid. Silahkan masukkan lagi tipe kendaraan menggunakan angka yang valid.\n"; 
            cout << "-----------------------------------\n"; 
            valid = 0; 
        } 
    } while (valid == 0); 
     
    selisihWaktu(datang, pulang, detikDatang, detikPulang, selisih); 
    jumlahBayar(selisih, bayar, durasi, tipe); 
     
    cout << "-----------------------------------\n"; 
    cout << "Jam Datang\t\t\t: " << datang.jam << ":" << datang.menit << ":" << datang.detik; 
    cout << "\nJam Pulang\t\t\t: " << pulang.jam << ":" << pulang.menit << ":" << pulang.detik; 
    cout << "\nLama Parkir\t\t\t: " << durasi.jam << ":" << durasi.menit << ":" << durasi.detik; 
    cout << "\nJenis Kendaraan\t\t\t: " << tipe; 
    cout << "\nBayar\t\t\t\t: Rp." << bayar; 
} 