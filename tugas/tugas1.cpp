#include <iostream>

using namespace std;

void tambah(double add1, double add2) {
    cout << "Hasil tambah: " << (add1 + add2) << endl;
}

void kurang(double sub1, double sub2) {
    cout << "Hasil kurang: " << (sub1 - sub2) << endl;
}

void kali(double mul1, double mul2) {
    cout << "Hasil kali: " << (mul1 * mul2) << endl;
}

void bagi(double div1, double div2) {
    if (div2 != 0) {
        cout << "Hasil bagi: " << (div1 / div2) << endl;
    } else {
        cout << "Error" << endl;
    }
}

int main() {
    int pilihan;
    char ulang;

    do {
        cout << "1. tambah" << endl;
        cout << "2. kurang" << endl;
        cout << "3. kali" << endl;
        cout << "4. bagi" << endl;

        cout << "Pilihan anda: ";
        cin >> pilihan;

        double n, j;

        switch (pilihan) {
            case 1:
                cout << "Masukkan bilangan untuk ditambah: ";
                cin >> n >> j;
                tambah(n, j);
                break;
            case 2:
                cout << "Masukkan bilangan untuk dikurangkan: ";
                cin >> n >> j;
                kurang(n, j);
                break;
            case 3:
                cout << "Masukkan bilangan untuk dikali: ";
                cin >> n >> j;
                kali(n, j);
                break;
            case 4:
                cout << "Masukkan bilangan untuk dibagi: ";
                cin >> n >> j;
                bagi(n, j);
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
        cout << "Ingin memilih menu lain (y/t)? ";
        cin >> ulang;
        cout << endl;

    } while (ulang != 't' && ulang != 'T');

    return 0;
}
