#include <iostream>
#include <mysql/mysql.h>
#include <sstream>
#include <fstream>

using namespace std;

const char *hostname = "127.0.0.1";
const char *user = "root";
const char *pass = "123";
const char *dbname = "toko";
unsigned int port = 31235;
const char *unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL *connect_db()
{
    MYSQL *conn = mysql_init(0);
    if (conn)
    {
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
        if (conn)
        {
            cout << "Connected to the database successfully." << endl;
        }
        else
        {
            cerr << "Connection failed: " << mysql_error(conn) << endl;
        }
    }
    else
    {
        cerr << "mysql_init failed" << endl;
    }
    return conn;
}

/*void tambah_barang(const string &nama_barang, const string &harga_barang, const string &jenis_barang, const string &stok_barang)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        string query = "INSERT INTO toko (nama_barang, harga_barang, jenis_barang, stok_barang) VALUES ('" + nama_barang + "', '" + harga_barang + "', '" + jenis_barang + "', '" + stok_barang + "')";
        if (mysql_query(conn, query.c_str()))
        {
            cerr << "INSERT failed." << mysql_error(conn) << endl;
        }
        else
        {
            cout << "User sucessfully added " << endl;
        }
        mysql_close(conn);
    }
}*/

bool login_kepalatoko(const string &username, const string &password)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream ss;
        ss << "SELECT * FROM kepalatoko WHERE username = '" << username << "' AND password = '" << password << "'";
        string query = ss.str();
        if (mysql_query(conn, query.c_str()))
        {
            cerr << "SELECT failed." << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        }
        MYSQL_RES *res = mysql_store_result(conn);
        if (res == nullptr || mysql_num_rows(res) == 0)
        {
            cerr << "Invalid login credentials." << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        }
        mysql_close(conn);
        return true;
    }
    return false;
}

bool login_customer(const string &username, const string &password)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream ss;
        ss << "SELECT * FROM customer WHERE username = '" << username << "' AND password = '" << password << "'";
        string query = ss.str();
        if (mysql_query(conn, query.c_str()))
        {
            cerr << "SELECT failed." << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        }
        MYSQL_RES *res = mysql_store_result(conn);
        if (res == nullptr || mysql_num_rows(res) == 0)
        {
            cerr << "Invalid login credentials." << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        }
        mysql_close(conn);
        return true;
    }
    return false;
}

void log_activity(const string &activity)
{
    ofstream logfile("activity.log", ios_base::app);
    if (logfile.is_open())
    {
        logfile << activity << endl;
        logfile.close();
    }
    else
    {
        cerr << "tidak dapat membuka file log" << endl;
    }
}

void tambah_barang(const string &nama_barang, const string &harga_barang, const string &jenis_barang, const string &stok_barang)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream ss;
        ss << "INSERT INTO barang (nama_barang, harga_barang, jenis_barang, stok_barang) VALUES ('" << nama_barang << "', '" << harga_barang << "', '" << jenis_barang << "', '" << stok_barang << "')";
        string query = ss.str();
        if (mysql_query(conn, query.c_str()))
        {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        }
        else
        {
            cout << "Barang successfully added" << endl;
        }
        mysql_close(conn);
    }
}

void jual_barang(const string &barang_id, int jumlah_terjual)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream ss;
        ss << "UPDATE barang SET stok_barang = stok_barang - " << jumlah_terjual << " WHERE barang_id = '" << barang_id << "'";
        string query = ss.str();
        if (mysql_query(conn, query.c_str()))
        {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        }
        else
        {
            cout << "Stok barang updated successfully" << endl;
        }
        mysql_close(conn);
    }
}

void delete_barang(const string &barang_id)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "DELETE FROM barang WHERE id =" << barang_id;
        if (mysql_query(conn, query.str().c_str())){
            cerr << "DELETE failed." <<  mysql_error(conn) << endl;
        } else {
            cout << "Barang sucessfully deleted " << endl;
        }
        mysql_close(conn);
    }
}

void update_stok(const string& barang_id, const string& stok_barang){
    MYSQL* conn = connect_db();
    if (conn){
        stringstream query;
        query << "UPDATE barang SET stok_barang = '" << stok_barang << "' WHERE id = " << barang_id;
        if (mysql_query(conn, query.str().c_str())){
            cerr << "UPDATE failed." <<  mysql_error(conn) << endl;
        } else {
            cout << "Stok Barang sucessfully updated " << endl;
        }
        mysql_close(conn);
    }
}

void tampilkan_barang()
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        if (mysql_query(conn, "SELECT * FROM barang"))
        {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
        }
        else
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (res == nullptr)
            {
                cerr << "STORE result failed: " << mysql_error(conn) << endl;
            }
            else
            {
                MYSQL_ROW row;
                cout << "Daftar Barang:" << endl;
                while ((row = mysql_fetch_row(res)) != nullptr)
                {
                    cout << "ID Barang: " << row[0] << ", Nama Barang: " << row[1] << ", Harga Barang: " << row[2] << ", Jenis Barang: " << row[3] << ", Stok Barang: " << row[4] << endl;
                }
                mysql_free_result(res);
            }
        }
        mysql_close(conn);
    }
}

void beli_barang(const string &barang_id, int jumlah_beli)
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream ss;
        ss << "UPDATE barang SET stok_barang = stok_barang - " << jumlah_beli << " WHERE barang_id = '" << barang_id << "'";
        string query = ss.str();
        if (mysql_query(conn, query.c_str()))
        {
            cerr << "Pembelian failed: " << mysql_error(conn) << endl;
        }
        else
        {
            cout << "Pembelian Berhasil" << endl;
        }
        mysql_close(conn);
    }
}

void menu_kepalatoko()
{   
    string nama_barang, harga_barang, jenis_barang, stok_barang;
    string id_barang;
    int jumlah_terjual;
    int jumlah_stok_baru;
    int pilihan;
    do{
        cout << "1. Tambah Barang" << endl;
        cout << "2. Delete Barang" << endl;
        cout << "3. Update Stok" << endl;
        cout << "4. Tampilkan Barang" << endl;
        cout << "5. exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
            case 1:
                cin.ignore();
                cout << "Masukkan nama barang: ";
                cin >> nama_barang;
                cout << "Masukkan harga barang: ";
                cin >> harga_barang;
                cout << "Masukkan jenis barang: ";
                cin >> jenis_barang;
                cout << "Masukkan stok barang: ";
                cin >> stok_barang;
                tambah_barang(nama_barang, harga_barang, jenis_barang, stok_barang);
                break;
            case 2:
                cin.ignore();
                cout << "Masukkan ID barang: ";
                cin >> id_barang;
                delete_barang(id_barang);
                break;
            case 3:
                cin.ignore();
                cout << "Masukkan ID barang: ";
                cin >> id_barang;
                cout << "Masukkan jumlah stok baru: ";
                cin >> stok_barang;
                update_stok(id_barang, stok_barang);
                break;
            case 4:
                tampilkan_barang();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);
}

void menu_customer()
{   
    string barang_id;
    int jumlah_terjual;
    int jumlah_beli;
    int pilihan;
    do{
        cout << "1. Beli Barang" << endl;
        cout << "2. exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
            case 1:
                tampilkan_barang();
                cout << "Masukkan ID barang: ";
                cin >> barang_id;
                cout << "Masukkan jumlah barang yang dibeli: ";
                cin >> jumlah_terjual;
                beli_barang(barang_id, jumlah_terjual);
                break;
            case 2:
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 2);
}

int main()
{
    int pilihan;
    string nama_barang, harga_barang, jenis_barang, stok_barang;
    string id_barang;
    string username, password;
    int jumlah_terjual;
    int jumlah_stok_baru;
    int jumlah_beli;

    cout << "Selamat datang di toko kami" << endl;
    cout << "Silahkan login terlebih dahulu" << endl;
    cout << "1. Login Kepala Toko" << endl;
    cout << "2. Login Customer" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    cin.ignore();
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    switch (pilihan) {
        case 1:
            cin.ignore();
            if (login_kepalatoko(username, password)) {
                menu_kepalatoko();
            } else {
                cout << "Login gagal" << endl;
            }
            break;
        case 2:
            cin.ignore();
            if (login_customer(username, password)) {
                menu_customer();
            } else {
                cout << "Login gagal" << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}