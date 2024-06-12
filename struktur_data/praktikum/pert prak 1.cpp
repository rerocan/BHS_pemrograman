#include <iostream>
using namespace std;

int main()
{
    string nama;
    string NIM;
    string fakultas;
    string jurusan;

    cout << "========================================" << endl;
    cout << "Program Mengisi Data dan tampilan data" << endl;
    cout << "=========================================" << endl;

    cout << "masukan nama mahasiswa :" << endl;
    getline(cin, nama);

    cout << "masukan NIM mahasiswa :" << endl;
    getline(cin, NIM);

    cout << "masukan fakultas mahasiswa :" << endl;
    getline(cin, fakultas);

    cout << "masukan jurusan mahasiswa :" << endl;
    getline(cin, jurusan);

    cout << "=====================================================" << endl;
    cout << "Terimakasih" << endl;
    cout << "" << endl;
    cout << "=====================================================" << endl;

    return 0;
}