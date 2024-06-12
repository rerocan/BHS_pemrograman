#include <iostream>
using namespace std;

struct film
{
    string judul;
    string namasutradara;
    float tahunrilis;
};

void clearScreen()
{
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

void isiDatafilm(film &flm)
{
    cout << "Masukkan judul: ";
    getline(cin, flm.judul);

    cout << "Masukkan nama sutradara: ";
    getline(cin, flm.namasutradara);

    cout << "Masukkan tahun rilis: ";
    cin >> flm.tahunrilis;

    cin.ignore();
}

int main()
{
    film flm1, flm2;

    clearScreen();
    cout << "=====" << endl;
    cout << "Isi data film 1" << endl;
    isiDatafilm(flm1);
    cout << "========" << endl;
    cout << "Isi data film 2" << endl;
    isiDatafilm(flm2);
    cout << endl;

    cout << "===============================================" << endl;
    cout << "Data film 1" << endl;
    cout << "judul : " << flm1.judul << endl;
    cout << "nama sutradara: " << flm1.namasutradara << endl;
    cout << "tahun rilis : " << flm1.tahunrilis << endl;
    cout << "===============================================" << endl;

    cout << "" << endl;

    cout << "===============================================" << endl;
    cout << "Data film 2" << endl;
    cout << "judul : " << flm2.judul << endl;
    cout << "nama sutradara: " << flm2.namasutradara << endl;
    cout << "tahun rilis : " << flm2.tahunrilis << endl;
    cout << "===============================================" << endl;
    cout << endl;

    return 0;
}