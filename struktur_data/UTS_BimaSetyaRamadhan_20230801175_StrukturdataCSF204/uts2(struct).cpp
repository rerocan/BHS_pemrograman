#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Struct untuk menyimpan data buku
struct Buku {
    string judul;
    string penulis;
    int tahunTerbit;
};

// Fungsi untuk menampilkan data buku
void tampilkanBuku(Buku buku[], int jumlah) {
    cout << "Daftar Buku:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << buku[i].judul << " oleh " << buku[i].penulis << " ("
             << buku[i].tahunTerbit << ")" << endl;
    }
}

// Fungsi untuk mengurutkan buku berdasarkan judul menggunakan bubble sort
void urutkanBuku(Buku buku[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (buku[j].judul > buku[j + 1].judul) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

// Fungsi untuk mengonversi string menjadi huruf kecil
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Fungsi untuk mencari buku berdasarkan judul menggunakan linear search
int cariBuku(Buku buku[], int jumlah, string judulDicari) {
    judulDicari = toLowerCase(judulDicari);
    for (int i = 0; i < jumlah; i++) {
        if (toLowerCase(buku[i].judul) == judulDicari) {
            return i; // Mengembalikan indeks buku jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika buku tidak ditemukan
}

int main() {
    int jumlahBuku = 5;

    // Inisialisasi array buku
    Buku buku[jumlahBuku] = {
        {"Solo Leveling", "Chugong", 2016},
        {"The Beginning After The End", "TurtleMe", 2018},
        {"The Second Coming of Gluttony", "Ro Yu-jin", 2017},
        {"The Legendary Moonlight Sculptor", "Nam Heesung", 2007},
        {"The King's Avatar", "Butterfly Blue", 2011}
    };

    // Menampilkan data buku sebelum diurutkan
    cout << "Sebelum diurutkan:" << endl;
    tampilkanBuku(buku, jumlahBuku);

    // Mengurutkan buku berdasarkan judul
    urutkanBuku(buku, jumlahBuku);

    // Menampilkan data buku setelah diurutkan
    cout << "\nSetelah diurutkan:" << endl;
    tampilkanBuku(buku, jumlahBuku);

    // Mencari buku berdasarkan judul
    string judulDicari;
    cout << "\nMasukkan judul buku yang ingin dicari: ";
    getline(cin, judulDicari);

    int indeks = cariBuku(buku, jumlahBuku, judulDicari);
    if (indeks != -1) {
        cout << "Buku ditemukan pada indeks ke-" << indeks << ": "
             << buku[indeks].judul << " oleh " << buku[indeks].penulis
             << " (" << buku[indeks].tahunTerbit << ")" << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }

    return 0;
}
