#include <iostream>
using namespace std;

enum JenisBarang
{
    Elektronik,
    Pakaian,
    Makanan,
    Minuman,
    ATK
};

struct Barang
{
    string nama_barang;
    string kode_barang;
    JenisBarang jenis_barang;
    double harga_barang;
};

void isiDataBarang(Barang &barang)
{
    cout << "Masukan Nama Barang   :";
    getline(cin, barang.nama_barang);

    cout << "Masukan Kode Barang   :";
    getline(cin, barang.kode_barang);

    cout << "Pilih Jenis Barang (0: Elektronik, 1: Pakaian, 2: Makanan, 3: Minuman, 4: ATK): ";
    int pilihan;
    cin >> pilihan;
    barang.jenis_barang = static_cast<JenisBarang>(pilihan);

    cout << "Masukan Harga Barang  :";
    cin >> barang.harga_barang;

    cin.ignore();
}

void tampilkanDataBarang(const Barang &barang)
{
    string jenis_barang[] = {"Elektronik", "Pakaian", "Makanan", "Minuman", "ATK"};

    cout << "Nama Barang     :" << barang.nama_barang << endl;
    cout << "Kode Barang     :" << barang.kode_barang << endl;
    cout << "Jenis Barang    :" << jenis_barang[barang.jenis_barang] << endl;
    cout << "Harga Barang    :Rp" << barang.harga_barang << endl;
}

void clearScreen()
{
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

int main()
{
    char lanjut;
    do
    {
        clearScreen();
        Barang barang;
        cout << "" << endl;
        cout << "=============================== Mengisi Data Barang ====================" << endl;
        isiDataBarang(barang);

        cout << "" << endl;
        cout << "=============================== Data Barang ====================" << endl;
        tampilkanDataBarang(barang);

        cout << "==================================================" << endl;
        cout << "Ingin Memasukan Data Barang Lagi ? (y/n)" << endl;
        cin >> lanjut;

        cin.ignore();
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "Program Selesai. Terima Kasih!" << endl;

    return 0;
}
