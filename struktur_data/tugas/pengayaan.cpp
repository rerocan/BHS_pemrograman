#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> bookStack;
    string operation;

    while (true) {
        cout << "Enter operation (push, pop, peek, isEmpty, size, quit): ";
        cin >> operation;

        if (operation == "push") {
            string book;
            cout << "Enter book name: ";
            cin.ignore();
            getline(cin, book);
            bookStack.push(book);
        } else if (operation == "pop") {
            if (!bookStack.empty()) {
                bookStack.pop();
                cout << "Book removed from the stack.\n";
            } else {
                cout << "Stack is empty.\n";
            }
        } else if (operation == "peek") {
            if (!bookStack.empty()) {
                cout << "Top book in the stack: " << bookStack.top() << "\n";
            } else {
                cout << "Stack is empty.\n";
            }
        } else if (operation == "isEmpty") {
            if (bookStack.empty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack is not empty.\n";
            }
        } else if (operation == "size") {
            cout << "Size of the stack: " << bookStack.size() << "\n";
        } else if (operation == "quit") {
            break;
        } else {
            cout << "Invalid operation.\n";
        }
    }

    return 0;
}