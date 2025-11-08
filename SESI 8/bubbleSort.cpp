/*
Nama     : Nena Haryadi Puspanegara
NPM      : 140810240034
Tanggal  : 12 Oktober 2025
Deskripsi: Program menyimpan dan mengolah nilai mahasiswa
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef string larik[256];
void swap(string& x, string& y){
    string temp = "";
    temp = x ;
    x = y;
    y = temp;
}

void cetak(larik a, int n){
    for(int k = 0; k < n; k++){
        cout << a[k] << " ";
    }
    cout << endl;
}

void bubbleSortAsc(larik& a, int n){ //menaik
    for(int i = n - 1; i > 0; i--){
        cout << "Proses ke- " << n - i << endl;
        cetak(a,n);
        for(int j = 0; j < i; j++){
            if(a[j] > a[j + 1]){
                swap (a[j],a[j+1]);
            }
            cetak(a,n);
        }
        cout << endl;
    }
}

void bubbleSortDsc(larik& a, int n){ //menurun
    for(int i = n - 1; i > 0; i--){
        cout << "Proses ke-" << n - i << ":" << endl;
        cetak(a,n);
        for(int j = 0; j < i; j++){
            if(a[j] < a[j+1]){
                swap(a[j], a[j+1]);
            }
            cetak(a,n);
        }
        cout << endl;
    }
}

int main(){
    larik a;
    int n;

    cout << "Masukkan jumlah data: ";
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        cout << "Data ke-" << i+1 << ": ";
        getline(cin, a[i]);
    }

    cout << endl;
    cout << "Pengurutan data secara Ascending dengan Bubble Sort" << endl;
    bubbleSortAsc(a,n);

    cout << "Pengurutan data secara Dascending dengan Bubble Sort" << endl;
    bubbleSortDsc(a,n);
}