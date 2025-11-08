#include <iostream>
using namespace std;

typedef string larik[256];

void swap(string& x, string& y){
    string temp = "";
    temp = x;
    x = y;
    y = temp;
}

void cetak(larik& a, int n){
    for(int k = 0; k < n; k++){
        cout << a[k] << " ";
    }
    cout << endl;
}

void shellSortAsc(larik& a, int banyakData) { 
    int j; 
    for (int gap = banyakData/2; gap > 0; gap /= 2) { 
        cetak(a, banyakData); 
         
        cout << "\nJarak = " << gap << endl; 
        cetak(a, banyakData); 
        for (int i = gap; i < banyakData; i++) { 
            string temp = a[i]; 
            for (j = i; j >= gap && temp < a[j-gap]; j -= gap) { 
                a[j] = a[j - gap]; 
            } 
            a[j] = temp; 
            cetak(a, banyakData); 
        } 
    } 
} 
 
void shellSortDesc(larik& a, int banyakData) { 
    int j; 
    for (int gap = banyakData/2; gap > 0; gap /= 2) { 
        cetak(a, banyakData); 
         
        cout << "\nJarak = " << gap << endl; 
        cetak(a, banyakData); 
        for (int i = gap; i < banyakData; i++) { 
            string temp = a[i]; 
            for (j = i; j >= gap && temp > a[j-gap]; j -= gap) { 
                a[j] = a[j - gap]; 
            } 
            a[j] = temp; 
            cetak(a, banyakData); 
        } 
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
    cout << "Data diurutkan secara Ascending dengan shell Sort" << endl;     //Pengurutan secara Ascending(menaik)
    cetak (a,n);
    shellSortAsc(a,n);

    cout << "Data diurutkan secara Descending dengan shell Sort" << endl;     //Pengurutan secara Descending(menurun)
    cetak (a,n);
    shellSortDesc(a,n);
}