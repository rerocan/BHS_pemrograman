#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    double nilai;
    // Tambahkan konstruktor untuk Mahasiswa
    Mahasiswa(const string &nama, const string &nim, double nilai) : nama(nama), nim(nim), nilai(nilai) {}
};

void tampilkanDataMahasiswa(const vector<Mahasiswa> &mahasiswa)
{
    cout << "Data Mahasiswa:\n\n";
    cout << setw(20) << left << "Nama" << setw(20) << "NIM" << setw(15) << "Nilai" << endl;
    for (const Mahasiswa &mhs : mahasiswa)
    {
        cout << "------------------------------------------------------------\n";
        cout << setw(20) << left << mhs.nama << setw(20) << mhs.nim << setw(15) << mhs.nilai << endl;
    }
    cout << "------------------------------------------------------------\n";
}

Mahasiswa cariMahasiswa(const vector<Mahasiswa> &mahasiswa, const string &nim)
{
    for (const Mahasiswa &mhs : mahasiswa)
    {
        if (mhs.nim == nim)
        {
            return mhs;
        }
    }
    // Jika tidak ditemukan, kembalikan Mahasiswa dengan atribut kosong
    return Mahasiswa("", "", 0.0);
}

double hitungRataRataNilai(const vector<Mahasiswa> &mahasiswa)
{
    double totalNilai = 0.0;
    for (const Mahasiswa &mhs : mahasiswa)
    {
        totalNilai += mhs.nilai;
    }
    return totalNilai / mahasiswa.size();
}

char jawaban;
int main()
{
    cout << "==========================\n";
    cout << "= PROGRAM DATA MAHASISWA =\n";
    cout << "==========================\n";
    cout << "made by kelompok 5\n\n";
    cout << "press enter to continue...";
    getchar();
    do
    {
        fflush(stdin);
        system("clear");
        vector<Mahasiswa> daftarMahasiswa;

        // Menambahkan data mahasiswa
        daftarMahasiswa.push_back(Mahasiswa("Farhan", "1234", 99.5));
        daftarMahasiswa.push_back(Mahasiswa("Bima", "2345", 90.0));
        daftarMahasiswa.push_back(Mahasiswa("Putra", "3456", 90.0));
        daftarMahasiswa.push_back(Mahasiswa("Dwi Firdaus", "4567", 90.0));
        daftarMahasiswa.push_back(Mahasiswa("Satria", "5678", 90.0));

        // Menampilkan data mahasiswa
        tampilkanDataMahasiswa(daftarMahasiswa);

        // Menghitung rata-rata nilai seluruh mahasiswa
        double rataRataNilai = hitungRataRataNilai(daftarMahasiswa);
        cout << "Rata-rata nilai seluruh mahasiswa: " << rataRataNilai << "\n";

        // Mencari mahasiswa berdasarkan NIM
        string nimCari;
        cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
        cin >> nimCari;

        Mahasiswa mahasiswaDitemukan = cariMahasiswa(daftarMahasiswa, nimCari);
        if (mahasiswaDitemukan.nama.empty())
        {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
        else
        {
            cout << "Mahasiswa ditemukan:\n\n";
            cout << setw(20) << left << "Nama" << setw(20) << "NIM" << setw(15) << "Nilai" << endl;
            cout << "------------------------------------------------------------\n";
            cout << setw(20) << left << mahasiswaDitemukan.nama << setw(20) << mahasiswaDitemukan.nim << setw(15) << mahasiswaDitemukan.nilai << endl;
            cout << "------------------------------------------------------------\n";
        }

        cout << "Apakah ingin mengulang? (y/n): ";
        cin >> jawaban;

    } while (jawaban == 'y' || jawaban == 'Y');

    return 0;
}