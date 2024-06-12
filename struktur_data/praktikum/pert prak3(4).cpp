#include <iostream>
using namespace std;

struct Address {
  string street;
  string city;
  string state;
  int zip;
};

struct Student {
  string name;
  int age;
  int grade;
  Address address;
};

void clearScreen()
{
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

int main() {
  Student student1;
  clearScreen();

  // Mengisi data student dari input pengguna
  cout << "Enter student's name: ";
  getline(cin, student1.name);

  cout << "Enter student's age: ";
  cin >> student1.age;

  cout << "Enter student's grade: ";
  cin >> student1.grade;

  cout << "Enter student's address:" << endl;
  cout << "Street: ";
  cin.ignore(); // Untuk membersihkan buffer sebelum mengambil getline()
  getline(cin, student1.address.street);

  cout << "City: ";
  getline(cin, student1.address.city);

  cout << "State: ";
  getline(cin, student1.address.state);

  cout << "ZIP code: ";
  cin >> student1.address.zip;

  // Menampilkan data student yang telah dimasukkan
  cout << "\nStudent Name: " << student1.name << endl;
  cout << "Age: " << student1.age << endl;
  cout << "Grade: " << student1.grade << endl;
  cout << "Address:" << endl;
  cout << student1.address.street << endl;
  cout << student1.address.city << ", " << student1.address.state << ", " << student1.address.zip << endl;

  return 0;
}
