#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertDepan(int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertTengah(int new_data, int position) {
    Node* new_node = new Node();
    new_node->data = new_data;
    Node* temp = head;
    for(int i=0; i<position-1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertBelakang(int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if(head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteDepan() {
    if(head == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteTengah(int position) {
    if(head == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        for(int i=0; i<position-1; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
}

void deleteBelakang() {
    if(head == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, data, position;
    while(1) {
        cout << "1.Insert Depan\n2.Insert Tengah\n3.Insert Belakang\n4.Delete Depan\n5.Delete Tengah\n6.Delete Belakang\n7.Display\n8.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertDepan(data);
                break;
            case 2:
                cout << "Enter data and position: ";
                cin >> data >> position;
                insertTengah(data, position);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                insertBelakang(data);
                break;
            case 4:
                deleteDepan();
                break;
            case 5:
                cout << "Enter position: ";
                cin >> position;
                deleteTengah(position);
                break;
            case 6:
                deleteBelakang();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}