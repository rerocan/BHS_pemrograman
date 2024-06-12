#include <iostream>
#include <string>
using namespace std;

void clearScreen() {
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

struct buku {
    string judul;
    string namapengarang;
    float tahunterbit;
};

int main(){
    buku bk1;
    buku bk2;

    clearScreen();
    cout << "=================================================="<<endl;
    bk1.judul = "aceng sang pengembala";
    bk1.namapengarang= "iqbal mpbn";
    bk1.tahunterbit = 2020;

    cout << "judul    :"<<bk1.judul<<endl;
    cout << "namapengarang   :"<<bk1.namapengarang<<endl;
    cout << "tahunterbit    :"<<bk1.tahunterbit<<endl;

    cout << "=================================================="<<endl;
    bk2.judul = "iqbal mpbn sang clutch master";
    bk2.namapengarang= "jarda";
    bk2.tahunterbit = 2023;

    cout << "judul    :"<<bk2.judul<<endl;
    cout << "namapengarang   :"<<bk2.namapengarang<<endl;
    cout << "tahunterbit    :"<<bk2.tahunterbit<<endl;

    return 0;

}