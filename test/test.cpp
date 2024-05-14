#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold order details
struct Order {
    string item;
    int jumlah;
    int price;
    int totalharga() const {
        return jumlah * price;
    }
};

// Function to clear the console screen
void clearScreen() {
    // ANSI escape code to clear screen
    cout << "\x1B[2J\x1B[H";
}

int main() {
    int menu, pilihan, jumlah, harga, total = 0;
    char menu_akhir;
    vector<Order> orders;

    do {
        cout << "Pilih Menu :" << endl;
        cout << "1. Makanan" << endl;
        cout << "2. Minuman" << endl;
        cout << "3. Tagihan" << endl;
        cout << "4. Keluar" << endl;
        
        cout << "Masukan pilihan anda: ";
        cin >> menu;

        switch (menu) {
            case 1:
                clearScreen();
                cout << "Pilihan Makanan:" << endl;
                cout << "1. Pecel Lele - 15000" << endl;
                cout << "2. Nasi Goreng - 10000" << endl;
                cout << "3. Kembali" << endl;
                
                cout << "Masukan pilihan anda: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    cout << "Masukan jumlah: ";
                    cin >> jumlah;
                    harga = 15000;
                    total += harga * jumlah;
                    orders.push_back({"Pecel Lele", jumlah, harga});
                } else if (pilihan == 2) {
                    cout << "Masukan jumlah: ";
                    cin >> jumlah;
                    harga = 10000;
                    total += harga * jumlah;
                    orders.push_back({"Nasi Goreng", jumlah, harga});
                } else if (pilihan == 3) {
                    break;
                } else {
                    cout << "Pilihan anda tidak valid" << endl;
                }
                break;

            case 2:
                clearScreen();
                cout << "Pilihan Minuman:" << endl;
                cout << "1. Es Teh Manis - 5000" << endl;
                cout << "2. Es Jeruk Anget - 7000" << endl;
                cout << "3. Kembali" << endl;
                
                cout << "Masukan pilihan anda: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    cout << "Masukan jumlah: ";
                    cin >> jumlah;
                    harga = 5000;
                    total += harga * jumlah;
                    orders.push_back({"Es Teh Manis", jumlah, harga});
                } else if (pilihan == 2) {
                    cout << "Masukan jumlah: ";
                    cin >> jumlah;
                    harga = 7000;
                    total += harga * jumlah;
                    orders.push_back({"Es Jeruk Anget", jumlah, harga});
                } else if (pilihan == 3) {
                    break;
                } else {
                    cout << "Pilihan anda tidak valid" << endl;
                }
                break;

            case 3:
                clearScreen();
                cout << "Tagihan:" << endl;
                for (const auto& order : orders) {
                    cout << order.item << " x " << order.jumlah << " = " << order.totalharga() << endl;
                }
                cout << "Total pembayaran: " << total << endl;
                break;

            case 4:
                clearScreen();
                cout << "Tagihan Akhir:" << endl;
                for (const auto& order : orders) {
                    cout << order.item << " x " << order.jumlah << " = " << order.totalharga() << endl;
                }
                cout << "Total pembayaran: " << total << endl;
                return 0;

            default:
                cout << "Pilihan anda tidak valid" << endl;
                break;
        }

        cout << "Apakah Anda Ingin Melanjutkan Program (y/n): ";
        cin >> menu_akhir;

        if (menu_akhir == 'Y' || menu_akhir == 'y') {
            clearScreen();
        }

    } while (menu_akhir == 'Y' || menu_akhir == 'y');

    clearScreen();
    cout << "Tagihan Akhir:" << endl;
    for (const auto& order : orders) {
        cout << order.item << " x " << order.jumlah << " = " << order.totalharga() << endl;
    }
    cout << "Total pembayaran: " << total << endl;

    return 0;
}
