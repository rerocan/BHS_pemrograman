#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void clearScreen()
{
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

void insertDepan(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertTengah(int new_data, int posisi)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    if (posisi == 0)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < posisi - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void insertBelakang(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteDepan()
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteTengah(int posisi)
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        Node *temp = head;
        if (posisi == 0)
        {
            head = head->next;
            delete temp;
            return;
        }
        Node *prev = NULL;
        for (int i = 0; i < posisi; i++)
        {
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}

void deleteBelakang()
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
}

void tampilkanData()
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        cout << "Data Linked List:" << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << " --> ";
            }
            temp = temp->next;
        }
        cout << " --> NULL" << endl;
    }
}

int main()
{
    int pilihan, data, posisi;
    while (1)
    {
        
        cout << "1. Insert depan" << endl;
        cout << "2. Insert tengah" << endl;
        cout << "3. Insert belakang" << endl;
        cout << "4. Delete depan" << endl;
        cout << "5. Delete tengah" << endl;
        cout << "6. Delete belakang" << endl;
        cout << "7. Tampilkan data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukan Pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            clearScreen();
            cout << "Masukan data: ";
            cin >> data;
            insertDepan(data);
            break;
        case 2:
            clearScreen();
            cout << "Masukan data dan posisi : ";
            cin >> data >> posisi;
            insertTengah(data, posisi);
            break;
        case 3:
            clearScreen();
            cout << "Masukan data: ";
            cin >> data;
            insertBelakang(data);
            break;
        case 4:
            clearScreen();
            deleteDepan();
            break;
        case 5:
            clearScreen();
            cout << "Masukan posisi: ";
            cin >> posisi;
            deleteTengah(posisi);
            break;
        case 6:
            clearScreen();
            deleteBelakang();
            break;
        case 7:
            clearScreen();
            tampilkanData();
            break;
        case 8:
            exit(0);
        default:
            cout << "Pilihan tidak valid" << endl;
        }
    }
    return 0;
}
