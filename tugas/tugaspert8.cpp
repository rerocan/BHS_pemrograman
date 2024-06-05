#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Shoe {
    string name;
    string condition;
    int price;
};

vector<Shoe> inventory;

void addShoe(string name, string condition, int price) {
    Shoe newShoe = {name, condition, price};
    inventory.push_back(newShoe);
}

void displayInventory() {
    cout << "Inventory:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << i + 1 << ". Name: " << inventory[i].name << ", Condition: " << inventory[i].condition << ", Price: " << inventory[i].price << endl;
    }
}

void buyShoe() {
    int choice;
    cout << "Enter the number of the shoe you want to buy: ";
    cin >> choice;
    if (choice >= 1 && choice <= inventory.size()) {
        cout << "You bought " << inventory[choice - 1].name << " for " << inventory[choice - 1].price << endl;
        inventory.erase(inventory.begin() + choice - 1);
    } else {
        cout << "Invalid choice!" << endl;
    }
}

void sellShoe() {
    string name, condition;
    int price;
    cout << "Enter the name of the shoe you want to sell: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    cout << "Enter the condition of the shoe (e.g., new, used): ";
    getline(cin, condition);
    cout << "Enter the price of the shoe: ";
    cin >> price;

    addShoe(name, condition, price);
    cout << name << " has been added to the inventory for " << price << endl;
}

int main() {
    addShoe("Nike Air Force 1", "new", 100);
    addShoe("Adidas Yeezy", "used", 200);

    int choice;
    do {
        cout << "\nMenu:\n1. Buy shoe\n2. Sell shoe\n3. Display inventory\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buyShoe();
                break;
            case 2:
                sellShoe();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}