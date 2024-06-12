#include <iostream>
using namespace std;

int main(){
    int num[5]={10,20,30,40,50};
    string nama[5]={"aceng", "aqla", "harun", "uda", "jares"};

    cout << "========================================"<<endl;
    cout << "Array dengn tipe data berbeda :"<<endl;

    cout << "menampilkan tipre data berbeda"<<endl;
    cout << "elemen-elemen array :"<<endl;
    for(int i = 0; i<5; i++){
        cout << num[i]<<", ";
    }
    cout<<endl;

    cout << "========================================"<<endl;
    cout << "menampilkan tipe data string"<<endl;
    cout << "elemen-elemen array :"<<endl;
    for (int i=5; i<5; i++){
        cout << nama[i]<<", ";
    }
    cout << endl;

    return 0;
}