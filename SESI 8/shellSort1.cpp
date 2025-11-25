#include <iostream>
using namespace std;

typedef int larik[256];

void shellSort(larik a, int jmlElement) {
    for (int gap = jmlElement/2; gap>0; gap/=2) {

        // insertion sort
        for (int i = gap; i<jmlElement; i++){ // i itu index untuk loop luar
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] < temp){// j ini untuk loop dalam dan ini bisa di ubah tanda buat asce dan desce
                a[j] = a[j - gap]; 
                j -= gap;           
            }
            a[j] = temp;
        }
    }
}

int main(){
    larik arr; 
    int n;

    cout << "Masukkan banyaknya elemen: ";
    cin >> n;
    cout << "Masukkan elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shellSort(arr, n);

    cout << "Array yang sudah terurut : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}