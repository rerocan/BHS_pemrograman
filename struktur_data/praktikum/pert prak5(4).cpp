//quick sort
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){
    int n, i;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    int arr[n];
    cout << "Masukkan elemen: ";
    for (i = 0; i < n; i++){
        cin >> arr[i];
    }
    int l = 0;
    int r = n - 1;
    int m = l + (r - l) / 2;
    cout << "Hasil pengurutan: ";
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}