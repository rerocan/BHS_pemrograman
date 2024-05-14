#include <iostream>

using namespace std;

int main (){

    bool huruf_besar = true;
    for (char abjad = 'A'; abjad <= 'Z'; abjad++){
        cout << abjad;
        if (huruf_besar){
            cout << abjad;
        } else {
            cout << char(tolower(abjad));
        }
        huruf_besar = !huruf_besar;
    }
    return 0;
}