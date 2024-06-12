#include <iostream>
using namespace std;

enum MataKuliah
{
    struktur_data,
    kalkulus1,
    orakom,
    organisasi_management,
    dsi
};

struct dosen
{
    string nama_dosen;
    int NIK_dosen;
    string alamat_dosen;
    MataKuliah mengajar;
};

void isidatadosen(dosen &dosen)
{
    cout << "Masukan Nama Dosen :";
    getline(cin, dosen.nama_dosen);

    cout << "Masukan NIK Dosen  :";
    cin >> dosen.NIK_dosen;

    cin.ignore();
    cout << "Masukan Alamat Dosen   :";
    getline(cin, dosen.alamat_dosen);

    cout << "Pilih Mata Kuliah Yang Di Ajarkan (0: struktur_data, 1: kalkulus1, 2: orakom, 3: organisasi_management, 4: DSI): ";
    int pilihan;
    cin >> pilihan;
    dosen.mengajar = static_cast<MataKuliah>(pilihan);

    cin.ignore();
}

void tampilkandatadosen(const dosen &dosen)
{
    string matakuliah[] = {"struktur_data", "kalkulus1", "orakom", "organisasi_management", "dsi"};


    cout << "Nama Dosen     :" << dosen.nama_dosen << endl;
    cout << "NIK Dosen      :" << dosen.NIK_dosen << endl;
    cout << "Alamat Dosen   :" << dosen.alamat_dosen << endl;
    cout << "Mata kuliah yang di ajarkan    :" << matakuliah[dosen.mengajar] << endl;
}

int main()
{
    char lanjut;
    do
    {
        dosen dosen;
        cout << "" << endl;
        cout << "=============================== Mengisi Data Dosen ====================" << endl;
        isidatadosen(dosen);

        cout << "" << endl;
        cout << "=============================== Data Dosen Yang Sudah Di Isi ====================" << endl;
        tampilkandatadosen(dosen);

        cout << "==================================================" << endl;
        cout << "Ingin Memasukan Data Dosen Lagi ? (y/n)" << endl;
        cin >> lanjut;

        cin.ignore();
    } while (lanjut == 'y' || lanjut == 'Y'); // Change 'N' to 'Y'

    cout << "Program Selesai. Terima Kasih!" << endl;

    return 0;
}
