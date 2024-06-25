//queue menggunakan package<queue>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> antrian;

    antrian.push(1);
    antrian.push(2);
    antrian.push(3);

    cout << "ukuran antrean: " << antrian.size() << endl;

    cout << "elemen depan: " << antrian.front() << endl;
        antrian.pop();
        cout << "elemen depan (setelah pop): " << antrian.front() << endl;
    return 0;
}