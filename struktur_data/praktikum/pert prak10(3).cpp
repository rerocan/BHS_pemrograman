//aplikasi queue antrean apotek
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct pasien {
    string nama;
    int nomorantrian;
};

int main(){
    queue<pasien> antrean;
    int nomorantrianterakhir = 0;

    while (true){
        cout << "1. Tambah pasien" << endl;
        cout << "2. Panggil pasien" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1){
            pasien pasienbaru;
            cout << "Nama pasien: ";
            cin >> pasienbaru.nama;
            nomorantrianterakhir++;
            pasienbaru.nomorantrian = nomorantrianterakhir;
            antrean.push(pasienbaru);
            cout << "Pasien " << pasienbaru.nama << " dengan nomor antrian " << pasienbaru.nomorantrian << " ditambahkan" << endl;
        } else if (pilihan == 2){
            if (antrean.empty()){
                cout << "Tidak ada pasien" << endl;
            } else {
                pasien p = antrean.front();
                antrean.pop();
                cout << "Pasien " << p.nama << " dengan nomor antrian " << p.nomorantrian << " dipanggil" << endl;
            }
        } else if (pilihan == 3){
            break;
        }
    }
    return 0;

}