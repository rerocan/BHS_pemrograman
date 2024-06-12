#include <iostream>
#include <string>
using namespace std;

void clearScreen() {
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

struct mahasiswa {
    string nim;
    string nama;
    float ipk;
};

int main(){
    mahasiswa mhs1;
    mahasiswa mhs2;

    clearScreen();
    cout << "=================================================="<<endl;
    mhs1.nim = "20230801175";
    mhs1.nama= "Bims";
    mhs1.ipk = 3.75;

    cout << "NIM    :"<<mhs1.nim<<endl;
    cout << "Nama   :"<<mhs1.nama<<endl;
    cout << "IPK    :"<<mhs1.ipk<<endl;

    cout << "=================================================="<<endl;
    mhs2.nim = "20230801176";
    mhs2.nama= "cengs";
    mhs2.ipk = 3.75;

    cout << "NIM    :"<<mhs2.nim<<endl;
    cout << "Nama   :"<<mhs2.nama<<endl;
    cout << "IPK    :"<<mhs2.ipk<<endl;

    return 0;

}