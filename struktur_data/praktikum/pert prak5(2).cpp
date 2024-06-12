#include <iostream>
using namespace std;

// Deklarasi fungsi selectionsort
void selectionsort(int arr[], int n);

int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Menginisialisasi larik dengan kurung kurawal
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array awal: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Proses selection sorting:\n ";
    selectionsort(arr, n);

    cout << "\nArray setelah sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Implementasi fungsi selectionsort
void selectionsort(int arr[], int n) {
    // Algoritma selection sort
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Tukar elemen terkecil dengan elemen pertama yang belum diurutkan
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

        // Tampilkan langkah-langkah proses selection sort
        cout << "Langkah " << i+1 << ": ";
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}
