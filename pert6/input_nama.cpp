#include <iostream>
using namespace std;

int main()
{

    char menu_akhir;
    string nama_depan;
    string nama_tengah;
    string nama_belakang;

    do
    {
        cout << "1. input" << endl;
        cout << "2. exit" << endl;

        int menu;
        cout << "masukan pilihan anda   :" << endl;
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Masukkan nama depan: ";
            cin >> nama_depan;
            cout << "Masukkan nama tengah: ";
            cin >> nama_tengah;
            cout << "Masukkan nama belakang: ";
            cin >> nama_belakang;
            cout << "Nama lengkap anda adalah: " << nama_depan << " " << nama_tengah << " " << nama_belakang << endl;
            break;

        case 2:
            return 0;
            break;

        default:
            break;
        }

        cout << "Apakah Anda Ingin Melanjutkan Program  (y/n):";
        cin >> menu_akhir;
    } while (menu_akhir == 'Y' || menu_akhir == 'y');

    return 0;
}
