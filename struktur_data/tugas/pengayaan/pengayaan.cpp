#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << "Pilihan Operasi Stack Buku:" << endl;
    cout << "1. Push (Tambah Buku)" << endl;
    cout << "2. Pop (Hapus Buku Teratas)" << endl;
    cout << "3. Peek (Lihat Buku Teratas)" << endl;
    cout << "4. isEmpty (Cek Apakah Stack Kosong)" << endl;
    cout << "5. Size (Jumlah Buku dalam Stack)" << endl;
    cout << "6. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    stack<string> bookStack;
    int choice;
    string book;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan nama buku yang ingin ditambahkan: ";
                cin.ignore(); // Membersihkan buffer input
                getline(cin, book);
                bookStack.push(book);
                cout << "Buku \"" << book << "\" telah ditambahkan ke stack." << endl;
                break;
            case 2:
                if (bookStack.empty()) {
                    cout << "Stack kosong, tidak ada buku yang dapat dihapus." << endl;
                } else {
                    cout << "Buku \"" << bookStack.top() << "\" telah dihapus dari stack." << endl;
                    bookStack.pop();
                }
                break;
            case 3:
                if (bookStack.empty()) {
                    cout << "Stack kosong, tidak ada buku di puncak stack." << endl;
                } else {
                    cout << "Buku teratas adalah \"" << bookStack.top() << "\"." << endl;
                }
                break;
            case 4:
                if (bookStack.empty()) {
                    cout << "Stack kosong." << endl;
                } else {
                    cout << "Stack tidak kosong." << endl;
                }
                break;
            case 5:
                cout << "Jumlah buku dalam stack: " << bookStack.size() << endl;
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }

        cout << endl;

    } while (choice != 6);
    
return 0;
}