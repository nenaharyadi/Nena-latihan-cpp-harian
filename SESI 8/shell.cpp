#include <iostream>
using namespace std;

void shellSort(int arr[], int n){
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++){
            int temp = arr[i]; 
            
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; 
    cout << endl; 
}

int main() {
    int arr[100]; 
    int n = 0;    
    cout << "Masukkan elemen (pisahkan dengan spasi, akhiri dengan -1): ";

    while (true) {
        int number;
        cin >> number;
        if (number == -1)
            break;
        arr[n++] = number;
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);
    shellSort(arr, n);
    cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}
