#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Membuat struct untuk barang
struct Barang
{
    string item;
    int jumlah;
    double harga;
};

// Membuat vector untuk menyimpan stock barang
vector<Barang> stock;

// Fungsi untuk menambah stock barang
void tambahBarang(string item, int jumlah, double harga)
{
    Barang barangBaru;
    barangBaru.item = item;
    barangBaru.jumlah = jumlah;
    barangBaru.harga = harga;
    stock.push_back(barangBaru);
}

// Fungsi untuk mencetak barang yang tersedia
void cetakBarang()
{
    cout << left << setw(20) << "item Barang" << setw(10) << "Jumlah" << setw(10) << "Harga" << endl;
    for (const auto &barang : stock)
    {
        cout << left << setw(20) << barang.item << setw(10) << barang.jumlah << setw(10) << barang.harga << endl;
    }
}

// Fungsi untuk mengupdate jumlah barang
void updateJumlahBarang(string item, int jumlahBaru)
{
    for (auto &barang : stock)
    {
        if (barang.item == item)
        {
            barang.jumlah = jumlahBaru;
            cout << "Jumlah barang " << item << " berhasil diperbarui.\n";
            return;
        }
    }
    cout << "Notifikasi: Barang dengan item " << item << " tidak ada.\n";
}

int main()
{
    int pilihan;
    string item;
    int jumlah;
    double harga;

    cout << "=========================================\n";
    cout << "= SELAMAT DATANG DI PROGRAM STOK BARANG =\n";
    cout << "=========================================\n";
    cout << "MADE BY KELOMPOK 5\n";
    cout << "Press enter to continue... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input barang\n";
        cout << "2. Update jumlah barang\n";
        cout << "3. Cetak stok\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan item barang       : ";
            getline(cin, item);
            cout << "Masukkan jumlah barang     : ";
            while (!(cin >> jumlah) || jumlah < 0)
            {
                cout << "Input tidak valid. Jumlah barang harus berupa angka positif. Silakan coba lagi.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Masukkan harga per barang  : ";
            while (!(cin >> harga) || harga < 0)
            {
                cout << "Input tidak valid. Harga barang harus berupa angka positif. Silakan coba lagi.\n ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            tambahBarang(item, jumlah, harga);
            break;
        case 2:
            cout << "Masukkan item barang yang ingin diupdate   : ";
            getline(cin, item);
            cout << "Masukkan jumlah barang baru                : ";
            while (!(cin >> jumlah) || jumlah < 0)
            {
                cout << "Input tidak valid. Jumlah barang harus berupa angka positif. Silakan coba lagi.\n ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            updateJumlahBarang(item, jumlah);
            break;
        case 3:
            cetakBarang();
            cout << "\nPress enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Menu hanya tersedia dari 1 hingga 4.\n";
            break;
        }
    } while (pilihan != 4);

    return 0;
}
