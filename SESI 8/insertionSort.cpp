#include <iostream>
#include <cstring>
using namespace std;

typedef string larik [256];

void swap(string& x, string& y){
    string temp = "";
    temp = x;
    x = y;
    y = temp;
}

void cetak(larik a, int n){
    for(int k = 0; k < n; k++){
        cout << a[k] << " ";
    }
    cout << endl;
}

// fungsi insertion sort untuk mengurutkan secara ascending 
void insertionSortAsc(larik& a, int banyakData) { 
    for (int i = 1; i < banyakData; i++) { 
        cout << "\nproses " << i << endl; 
        cetak(a, banyakData); 
 
        for (int j = i; j >= 1; j--) { 
            if (a[j] < a[j - 1]) { 
                swap (a[j], a[j - 1]); 
            } 
            else break; 
        } 
        cetak(a, banyakData); 
    } 
} 
 
// fungsi insertion sort untuk mengurutkan secara descending 
void insertionSortDesc(larik& a, int banyakData) { 
    for (int i = 1; i < banyakData; i++) { 
        cout << "\nproses " << i << endl; 
        cetak(a, banyakData); 
 
        for (int j = i; j >= 1; j--) { 
            if (a[j] > a[j - 1]) { 
                swap (a[j], a[j - 1]); 
            } 
            else break; 
        } 
        cetak(a, banyakData); 
    } 
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
    cout << "Data diurutkan secara Ascending dengan insertion Sort" << endl;     //Pengurutan secara Ascending(menaik)
    cetak (a,n);
    insertionSortAsc(a,n);

    cout << "Data diurutkan secara Descending dengan insertion Sort" << endl;     //Pengurutan secara Descending(menurun)
    cetak (a,n);
    insertionSortDesc(a,n);
}