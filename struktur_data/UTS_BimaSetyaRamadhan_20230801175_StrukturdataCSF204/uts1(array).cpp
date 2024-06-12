#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk menampilkan data buku
void tampilkanBuku(string judul[], string penulis[], int tahunTerbit[], int jumlah) {
    cout << "Daftar Buku:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << judul[i] << " oleh " << penulis[i] << " ("
             << tahunTerbit[i] << ")" << endl;
    }
}

// Fungsi untuk mengurutkan buku berdasarkan judul menggunakan bubble sort
void urutkanBuku(string judul[], string penulis[], int tahunTerbit[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (judul[j] > judul[j + 1]) {
                swap(judul[j], judul[j + 1]);
                swap(penulis[j], penulis[j + 1]);
                swap(tahunTerbit[j], tahunTerbit[j + 1]);
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
int cariBuku(string judul[], int jumlah, string judulDicari) {
    judulDicari = toLowerCase(judulDicari);
    for (int i = 0; i < jumlah; i++) {
        if (toLowerCase(judul[i]) == judulDicari) {
            return i; // Mengembalikan indeks buku jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika buku tidak ditemukan
}

int main() {
    int jumlahBuku = 5;

    // Inisialisasi array buku
    string judul[jumlahBuku] = {
        "Solo Leveling",
        "The Beginning After The End",
        "The Second Coming of Gluttony",
        "The Legendary Moonlight Sculptor",
        "The King's Avatar"
    };

    string penulis[jumlahBuku] = {
        "Chugong",
        "TurtleMe",
        "Ro Yu-jin",
        "Nam Heesung",
        "Butterfly Blue"
    };

    int tahunTerbit[jumlahBuku] = {2016, 2018, 2017, 2007, 2011};

    // Menampilkan data buku sebelum diurutkan
    cout << "Sebelum diurutkan:" << endl;
    tampilkanBuku(judul, penulis, tahunTerbit, jumlahBuku);

    // Mengurutkan buku berdasarkan judul
    urutkanBuku(judul, penulis, tahunTerbit, jumlahBuku);

    // Menampilkan data buku setelah diurutkan
    cout << "\nSetelah diurutkan:" << endl;
    tampilkanBuku(judul, penulis, tahunTerbit, jumlahBuku);

    // Mencari buku berdasarkan judul
    string judulDicari;
    cout << "\nMasukkan judul buku yang ingin dicari: ";
    getline(cin, judulDicari);

    int indeks = cariBuku(judul, jumlahBuku, judulDicari);
    if (indeks != -1) {
        cout << "Buku ditemukan pada indeks ke-" << indeks << ": "
             << judul[indeks] << " oleh " << penulis[indeks]
             << " (" << tahunTerbit[indeks] << ")" << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }

    return 0;
}
