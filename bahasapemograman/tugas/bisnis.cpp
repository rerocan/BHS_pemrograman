#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur untuk menyimpan data pengguna
struct User {
    string username;
    string password;
    string email;
};

// Struktur untuk menyimpan data sneakers
struct Sneaker {
    string brand;
    string model;
    double price;
    string condition;
};

// Fungsi untuk registrasi pengguna
void registerUser(vector<User>& users) {
    User newUser;
    cout << "Masukkan username: ";
    cin >> newUser.username;
    cout << "Masukkan password: ";
    cin >> newUser.password;
    cout << "Masukkan email: ";
    cin >> newUser.email;
    users.push_back(newUser);
    cout << "Registrasi berhasil!\n";
}

// Fungsi untuk login pengguna
bool loginUser(vector<User>& users) {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            cout << "Login berhasil!\n";
            return true;
        }
    }
    cout << "Login gagal! Username atau password salah.\n";
    return false;
}

// Fungsi untuk menambah sneakers
void addSneaker(vector<Sneaker>& sneakers) {
    Sneaker newSneaker;
    cout << "Masukkan merek: ";
    cin >> newSneaker.brand;
    cout << "Masukkan model: ";
    cin >> newSneaker.model;
    cout << "Masukkan harga: ";
    cin >> newSneaker.price;
    cout << "Masukkan kondisi: ";
    cin >> newSneaker.condition;
    sneakers.push_back(newSneaker);
    cout << "Sneakers berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan daftar sneakers
void displaySneakers(const vector<Sneaker>& sneakers) {
    cout << "Daftar Sneakers:\n";
    for (const auto& sneaker : sneakers) {
        cout << "Merek: " << sneaker.brand << ", Model: " << sneaker.model
             << ", Harga: " << sneaker.price << ", Kondisi: " << sneaker.condition << endl;
    }
}

int main() {
    vector<User> users;
    vector<Sneaker> sneakers;
    int choice;
    
    do {
        cout << "1. Registrasi\n2. Login\n3. Tambah Sneakers\n4. Tampilkan Sneakers\n5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(users);
                break;
            case 2:
                loginUser(users);
                break;
            case 3:
                addSneaker(sneakers);
                break;
            case 4:
                displaySneakers(sneakers);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan Kshoe's!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}