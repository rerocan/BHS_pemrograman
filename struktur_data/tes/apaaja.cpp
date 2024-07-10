#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Item
{
    string name;
    string price;
};

map<string, string> loadUsers()
{
    map<string, string> users;
    ifstream file("users.txt");
    if (file.is_open())
    {
        string username, password;
        while (file >> username >> password)
        {
            users[username] = password;
        }
        file.close();
    }
    return users;
}

void saveUser(const string &username, const string &password)
{
    ofstream file("users.txt", ios::app);
    if (file.is_open())
    {
        file << username << " " << password << endl;
        file.close();
    }
}

bool registerUser(map<string, string> &users)
{
    string username, password;
    cout << "Masukin Username Baru: ";
    cin >> username;
    if (users.find(username) != users.end())
    {
        cout << "Username Udah Terdaftar. Coba Pake Username Lain.\n";
        return false;
    }
    cout << "Masukin Password Baru: ";
    cin >> password;
    users[username] = password;
    saveUser(username, password);
    cout << "Pendaftaran Berhasil, MANTAP.\n";
    return true;
}

bool loginUser(const map<string, string> &users)
{
    string username, password;
    cout << "Masukin Username: ";
    cin >> username;
    cout << "Masukin Password: ";
    cin >> password;
    if (users.find(username) != users.end() && users.at(username) == password)
    {
        cout << "Login Berhasil. WELLCOME TO THE PROGRAM BRAYYY, " << username << "!\n";
        return true;
    }
    else
    {
        cout << "Username Atau Password Lu Salah. Coba Masukin Lagi Yang Bener. (NGAREP PROGRAM NYA TETEP JALAN YA KLO ASAL MASUKIN USER SM PW? WKWKWKWK)\n";
        return false;
    }
}

void saveItems(const vector<Item> &items)
{
    ofstream file("items.txt");
    if (file.is_open())
    {
        for (const auto &item : items)
        {
            file << item.name << " " << item.price << endl;
        }
        file.close();
    }
}

vector<Item> loadItems()
{
    vector<Item> items;
    ifstream file("items.txt");
    if (file.is_open())
    {
        string name;
        string price;
        while (file >> name >> price)
        {
            items.push_back({name, price});
        }
        file.close();
    }
    return items;
}

void addItem(vector<Item> &items)
{
    string name;
    string price;
    cout << "Masukkan Nama Item: ";
    cin >> name;
    cout << "Masukkan Harga Item: ";
    cin >> price;
    items.push_back({name, price});
    saveItems(items);
    cout << "Item Berhasil Ditambahkan.\n";
}

void viewItems(const vector<Item> &items)
{
    cout << "Daftar Item Yang Tersedia:\n";
    for (size_t i = 0; i < items.size(); ++i)
    {
        cout << i + 1 << ". " << items[i].name << " - " << items[i].price << endl;
    }
}

void updateItem(vector<Item> &items)
{
    int index;
    cout << "Masukkan Nomor Id Item Yang Ingin Diupdate: ";
    cin >> index;
    if (index > 0 && index <= items.size())
    {
        string name;
        string price;
        cout << "Masukkan Nama Item Baru: ";
        cin >> name;
        cout << "Masukkan Harga Item Baru: ";
        cin >> price;
        items[index - 1] = {name, price};
        saveItems(items);
        cout << "Item Berhasil Diupdate, MANTAP.\n";
    }
    else
    {
        cout << "Nomor Id Item Tidak Valid Atau Tidak Ditemukan, COBA CARI YANG BENER BRAYY NOMOR ID NYA BERAPA.\n";
    }
}

void deleteItem(vector<Item> &items)
{
    int index;
    cout << "Masukkan Nomor Item Yang Ingin Dihapus: ";
    cin >> index;
    if (index > 0 && index <= items.size())
    {
        items.erase(items.begin() + index - 1);
        saveItems(items);
        cout << "Item Berhasil Dihapus.\n";
    }
    else
    {
        cout << "Nomor Id Item Tidak Valid Atau Tidak Ditemukan, COBA CARI YANG BENER BRAYY NOMOR ID NYA BERAPA.\n";
    }
}

void mainProgram()
{
    vector<Item> items = loadItems();
    int choice;

    cout << "===== PROGRAM TOSERBA =====\n";
    cout << "1. Membuat Data Item Yang Akan Ditambahkan\n";
    cout << "2. Melihat Data Item Yang Tersedia\n";
    cout << "3. Update Data Item\n";
    cout << "4. Hapus Data Item\n";
    cout << "5. Keluar Program\n";
    cout << "Pilih Opsi: ";
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            addItem(items);
            break;
        case 2:
            viewItems(items);
            break;
        case 3:
            updateItem(items);
            break;
        case 4:
            deleteItem(items);
            break;
        default:
            cout << "Pilihan Tidak Valid. Silakan Coba Lagi.\n";
            break;
        }
        cout << "===== PROGRAM TOSERBA =====\n";
        cout << "1. Membuat Data Item Yang Akan Ditambahkan\n";
        cout << "2. Melihat Data Item Yang Tersedia\n";
        cout << "3. Update Data Item\n";
        cout << "4. Hapus Data Item\n";
        cout << "5. Keluar Program\n";
        cout << "Pilih Opsi:  ";
        cin >> choice;
    }
}

int main()
{
    map<string, string> users = loadUsers();
    int choice;
    bool loggedIn = false;

    cout << "Selamat Datang Di Program TOSERBA (TOKO SERBA ADA)\n";
    cout << "1. Daftar Akun\n";
    cout << "2. Login\n";
    cout << "3. Keluar Program\n";
    cout << "Pilih opsi: ";
    cin >> choice;

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            if (registerUser(users))
            {
                cout << "Silakan Login.\n";
            }
            break;
        case 2:
            if (loginUser(users))
            {
                loggedIn = true;
            }
            break;
        default:
            cout << "Pilihan Tidak Valid. Silakan Coba Lagi.\n";
            break;
        }

        if (loggedIn)
        {
            mainProgram();
            break;
        }

        cout << "1. Daftar Akun\n";
        cout << "2. Login\n";
        cout << "3. Keluar Program\n";
        cout << "Pilih Opsi: ";
        cin >> choice;
    }

    cout << "Terima Kasih Telah Menggunakan Program Ini.\n";
    return 0;
}