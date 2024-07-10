#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

struct Product
{
    string name;
    float price;
};

unordered_map<string, string> users;     // username, password
unordered_map<string, Product> products; // productID, Product

bool login()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username] == password)
    {
        cout << "Login successful\n";
        return true;
    }
    else
    {
        cout << "Login failed\n";
        return false;
    }
}

void registerUser()
{
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    if (users.find(username) == users.end())
    {
        users[username] = password;
        cout << "User registered successfully\n";
    }
    else
    {
        cout << "Username already exists\n";
    }
}

void createProduct()
{
    string id, name;
    float price;
    cout << "Enter product ID: ";
    cin >> id;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;

    products[id] = {name, price};
    cout << "Product created successfully\n";
}

void readProducts()
{
    for (const auto &p : products)
    {
        cout << "ID: " << p.first << ", Name: " << p.second.name << ", Price: " << p.second.price << endl;
    }
}

void updateProduct()
{
    string id;
    cout << "Enter product ID to update: ";
    cin >> id;

    if (products.find(id) != products.end())
    {
        cout << "Enter new name: ";
        cin >> products[id].name;
        cout << "Enter new price: ";
        cin >> products[id].price;
        cout << "Product updated successfully\n";
    }
    else
    {
        cout << "Product not found\n";
    }
}

void deleteProduct()
{
    string id;
    cout << "Enter product ID to delete: ";
    cin >> id;

    if (products.erase(id))
    {
        cout << "Product deleted successfully\n";
    }
    else
    {
        cout << "Product not found\n";
    }
}

void saveUsers()
{
    ofstream file("users.txt");
    for (const auto &user : users)
    {
        file << user.first << " " << user.second << "\n";
    }
    file.close();
}

void loadUsers()
{
    ifstream file("users.txt");
    string username, password;
    while (file >> username >> password)
    {
        users[username] = password;
    }
    file.close();
}

int main()
{
    loadUsers(); // Memuat pengguna saat program dimulai
    int choice;

    while (true)
    {
        cout << "\n1. Login\n2. Register\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (login())
            {
                int userChoice;
                do
                {
                    cout << "\n3. Create Product\n4. Read Products\n5. Update Product\n6. Delete Product\n0. Logout\nEnter choice: ";
                    cin >> userChoice;
                    switch (userChoice)
                    {
                    case 1:
                        system("clear");
                        createProduct();
                        break;
                    case 2:
                        system("clear");
                        readProducts();
                        break;
                    case 3:
                        system("clear");
                        updateProduct();
                        break;
                    case 4:
                        system("clear");
                        deleteProduct();
                        break;
                    case 0:
                        system("clear");
                        cout << "Logged out.\n";
                        break;
                    default:
                        cout << "Invalid choice\n";
                    }
                } while (userChoice != 0);
            }
            break;
        case 2:
            system("clear");
            registerUser();
            break;
        case 0:
            saveUsers(); // Menyimpan pengguna sebelum keluar
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}