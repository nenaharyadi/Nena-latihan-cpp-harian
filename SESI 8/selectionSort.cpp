#include <iostream>
#include <cstring>
using namespace std;

typedef string larik [256]; 

void tukar(string& x, string& y){
    string temp = "";
    temp = x;
    x = y;
    y = temp;
}

void printLarik(larik a, int n){
    for(int k = 0; k < n; k++){
        cout << a[k] << " ";
    }
    cout << endl;
}

void selectionSortAsce(larik& a, int n){       //Fungsi Selection Sort untuk mengurutkan secara Ascending 
    int posisi;
    for (int i = 0; i < n - 1; i++){
    cout << "Proses ke- " << i + 1 <<endl;
    posisi = i;
    for (int j = i + 1; j < n; j++) {
        if (a[posisi] > a[j]) {
        posisi = j; 
            }
        }
        tukar(a[i], a[posisi]);
        printLarik (a,n);
    }
    cout << endl;
}

void selectionSortDesce(larik& a, int n) {      //Fungsi Selection Sort untuk mengurutkan secara Descending
    int posisi;
    for (int i = 0; i < n - 1; i++){
    cout << "Proses ke- " << i + 1 << endl;
    posisi = i;
    for (int j = i + 1; j < n; j++) {
        if (a[posisi] < a[j]) {
            posisi = j; 
            }
        }
        tukar(a[i], a[posisi]);
        printLarik (a,n);
    }
    cout << endl;
}

int main(){
    larik a;
    int n;

    cout << "Masukkan jumlah elemen: " ;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        cout << "Data ke-" << i + 1 << ": ";
        getline(cin >> ws, a[i]);
    }

    cout << endl;
    cout << "Data diurutkan secara Ascending dengan Selection Sort" << endl;     //Pengurutan secara Ascending(menaik)
    printLarik (a,n);
    selectionSortAsce(a,n);

    cout << "Data diurutkan secara Descending dengan Selection Sort" << endl;     //Pengurutan secara Descending(menurun)
    printLarik (a,n);
    selectionSortDesce(a,n);
}
