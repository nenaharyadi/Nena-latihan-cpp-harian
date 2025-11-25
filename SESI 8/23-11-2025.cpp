//binary search

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key){
    int left = 0, right = n - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] == key) return mid;
        if(arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    const int MAX = 100;
    int arr[MAX];
    int n, key;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Masukkan " << n << " data: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nData sebelum diurutkan: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    bubbleSort(arr, n);

    cout << "\nData setelah diurutkan: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << "\n\nMasukkan data yang dicari: ";
    cin >> key;

    int hasil = binarySearch(arr, n, key);

    if(hasil != -1)
        cout << "Data ditemukan pada indeks ke-" << hasil;
    else
        cout << "Data tidak ditemukan.";

    return 0;
}