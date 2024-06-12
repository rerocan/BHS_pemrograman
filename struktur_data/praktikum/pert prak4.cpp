/*sequential search*/
#include <iostream>
using namespace std;

int main (){
    int arr[7] = {2, 5, 7, 12, 18, 25, 30};
    int n = sizeof(arr) / sizeof (arr[0]);
    int x =  18 ; // Angka yang di cari 
    int result = -1;

    for (int i = 0; i < n; i++){
        if (arr[i] == x){
            result = i;
            break;
        }
    }

    if (result != -1){
        cout << "Angka  ditemukan Di Indeks Ke-" << result << endl;
    }else {
        cout << "Angka Tidak DiTemukan" << endl;
    }

    return 0;
}