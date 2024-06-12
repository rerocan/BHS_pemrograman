/*sequential sorted seaarching descending*/

#include <iostream>

using namespace std;

int main (){

    int arr[7] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    int i = size - 1;

    while (i >= 0 && arr[i] != x){
        i--;
    }

    if (i >= 0) {
        cout << "Elemen ditemukan di indeks :" << i << endl;
    }else{
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}