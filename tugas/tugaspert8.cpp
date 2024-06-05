//jual beli sepatu sederhana
#include <iostream>
#include <vector>
#include <string>

struct Shoe {
    std::string name;
    std::string condition;
    int price;
};

std::vector<Shoe> inventory;

void addShoe(std::string name, std::string condition, int price) {
    Shoe newShoe = {name, condition, price};
    inventory.push_back(newShoe);
}

void displayInventory() {
    for (const auto& shoe : inventory) {
        std::cout << "Name: " << shoe.name << ", Condition: " << shoe.condition << ", Price: " << shoe.price << std::endl;
    }
}

void sellShoe(std::string name) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->name == name) {
            std::cout << it->name << " sold for " << it->price << std::endl;
            inventory.erase(it);
            break;
        }
    }
}

int main() {
    addShoe("Nike Air Force 1", "new", 100);
    addShoe("Adidas Yeezy", "used", 200);
    displayInventory();
    sellShoe("Nike Air Force 1");
    displayInventory();
    return 0;
}