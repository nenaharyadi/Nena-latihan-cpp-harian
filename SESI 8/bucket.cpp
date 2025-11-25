#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bucketSort(int arr[], int n) {
    const int bucketCount = 10; // jumlah bucket
    int buckets[bucketCount][100];
    int bucketSizes[bucketCount] = {0};

    // Cari nilai minimum dan maksimum
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // Masukkan elemen ke bucket sesuai nilai relatif
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minVal) * bucketCount / (maxVal - minVal + 1);
        if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Urutkan setiap bucket
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0)
            sort(buckets[i], buckets[i] + bucketSizes[i]);
    }

    // Gabungkan hasilnya
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[100], n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan " << n << " elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray sebelum diurutkan: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "\nArray setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}
