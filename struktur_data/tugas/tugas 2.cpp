#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

struct Transaksi
{
    string jenis;
    double jumlah;
    string keterangan;
};

void displayTransaction(const Transaksi &t)
{
    cout << setw(15) << left << t.jenis << setw(15) << "Rp. " + to_string(t.jumlah) << setw(15) << t.keterangan << endl;
}

double hitungTotalPemasukan(const vector<Transaksi> &transaksi)
{
    double totalPemasukan = 0.0;
    for (const auto &t : transaksi)
    {
        if (t.jenis == "Pemasukan")
        {
            totalPemasukan += t.jumlah;
        }
    }
    return totalPemasukan;
}

double hitungTotalPengeluaran(const vector<Transaksi> &transaksi)
{
    double totalPengeluaran = 0.0;
    for (const auto &t : transaksi)
    {
        if (t.jenis == "Pengeluaran")
        {
            totalPengeluaran += t.jumlah;
        }
    }
    return totalPengeluaran;
}

Transaksi inputTransaction()
{
    Transaksi t;
    int jenisInt;

    do
    {
        cout << "Jenis transaksi:\n";
        cout << "1. Pemasukan\n";
        cout << "2. Pengeluaran\n";
        cout << "Pilih jenis transaksi (1/2): ";
        cin >> jenisInt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (jenisInt != 1 && jenisInt != 2);

    t.jenis = (jenisInt == 1) ? "Pemasukan" : "Pengeluaran";

    cout << "Jumlah: ";
    cin >> t.jumlah;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Keterangan: ";
    getline(cin, t.keterangan);

    return t;
}

int main()
{
    vector<Transaksi> transaksi;
    char input;
    cout << "===================================================" << endl;
    cout << "= SELAMAT DATANG DI APLIKASI MANAJEMEN TRANSAKSI! =" << endl;
    cout << "===================================================" << endl;
    cout << "MADE BY KELOMPOK 5" << endl;
    cout << "press any key to continue...";
    cin.get();

    do
    {
        Transaksi t = inputTransaction();
        transaksi.push_back(t);

        cout << "Apakah ada transaksi lain? (y/n): ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (input == 'y' || input == 'Y');

    // Menampilkan detail transaksi
    cout << endl
         << "Detail Transaksi:" << endl;
    cout << setw(15) << left << "Jenis" << setw(15) << "Jumlah" << setw(15) << "Keterangan" << endl;
    for (const auto &t : transaksi)
    {
        displayTransaction(t);
    }

    // Menampilkan total pemasukan dan pengeluaran
    cout << endl
         << "Total Pemasukan: Rp. " << fixed << setprecision(2) << hitungTotalPemasukan(transaksi) << endl;
    cout << "Total Pengeluaran: Rp. " << fixed << setprecision(2) << hitungTotalPengeluaran(transaksi) << endl;

    return 0;
}
