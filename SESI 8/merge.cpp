#include <iostream>
using namespace std;

void printArrayRange(int arr[], int left, int right) {
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // jumlah elemen di bagian kiri
    int n2 = right - mid;    // jumlah elemen di bagian kanan

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) { //gabungkan 
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Menggabungkan bagian [" << left << "..." << right << "]: ";
    printArrayRange(arr, left, right);
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2; // cari titik tengah
        mergeSort(arr, left, mid); //urutkan bagian kiri
        mergeSort(arr, mid + 1, right); //bagian kanan
        merge(arr, left, mid, right); //keduanya
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int n = 0;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan " << n << " elemen: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    /*cout << "Masukkan elemen (akhiri dengan -1): ";
    while (true){
        int number;
        cin >> number;
        if (number == -1) break; // berhenti jika input -1
        arr[n++] = number;
    }*/

    cout << "\nArray sebelum diurutkan: ";
    printArray(arr, n);

    cout << "\n=== Proses Merge Sort ===\n";
    mergeSort(arr, 0, n - 1);

    cout << "\nArray setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}