#include <iostream>
#include "user.h"
#include "voucher.h"
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    list_user L1;
    adr_user A1;
    infotype_user X1;

    list_vc L2;
    adr_vc A2;
    infotype_vc X2;
    int n;
    string nama, namaU, namaV;
    createListUser(L1);
    createListVc(L2);
    bool menu = true;

    while(menu) {
        cout <<"=========================================="<< endl;
        cout << "1. Insert Data User: " << endl;
        cout << "2. Insert Data Voucher: " << endl;
        cout << "3. Delete Data User: " << endl;
        cout << "4. Delete Data Voucher: " << endl;
        cout << "5. Show Data User: " << endl;
        cout << "6. Show Data Voucher: " << endl;
        cout << "7. Hitung Data User: " << endl;
        cout << "8. Hitung Data Voucher: " << endl;
        cout << "9. Tambah Relasi: " << endl;
        cout << "10. Hapus Relasi: " << endl;
        cout << "0. Keluar " << endl;
        cout << "========================================="<< endl << endl;

        cout << "Pilihan: ";
        cin >> n;
        switch(n){
        case 0:
            menu = false;break;
        case 1:
            cout << "Masukan Nama User: "; cin >> X1.nama;
            cout << "Masukan Username: "; cin >> X1.akun;
            A1 = alokasi_user(X1);
            insertFirstUser(L1, A1);
            cout << endl;
            showUser(L1);
            cout<<"tekan enter";_getch();system("cls");break;
        case 2:
            cout << "Masukan Nama Voucher: "; cin >> X2.nama_vc;
            cout << "Masukan kode: "; cin >> X2.kode;
            A2 = alokasi_vc(X2);
            insertFirstVc(L2, A2);
            cout << endl;
            showVc(L2);
            cout<<"tekan enter";_getch();system("cls");break;
        case 3:
            cout << "Masukan Nama User: "; cin >> nama;
            deleteElementUser(L1, nama);
            cout<<"tekan enter";_getch();system("cls");break;
        case 4:
            cout << "Masukan Nama User: "; cin >> nama;
            deleteElementVc(L2, nama);
            cout<<"tekan enter";_getch();system("cls");break;
        case 5:
            showUser(L1);
            cout<<"Tekan enter";_getch();system("cls");break;
        case 6:
            showVc(L2);
            cout<<"tekan enter";_getch();system("cls");break;
        case 7:
            {
            int hitungUser = count_user(L1);
            cout << "Jumlah user yang terdaftar adalah " << hitungUser <<endl;
            cout<<"tekan enter";_getch();system("cls");break;
            }
        case 8:
            {
            int hitungVc = countVc(L2);
            cout << "Jumlah voucher yang tersedia adalah " << hitungVc <<endl;
            cout<<"tekan enter";_getch();system("cls");break;
            }
        case 9:


            cout << "Masukan Nama User: "; cin >> namaU;
            A1 = findUser(L1, namaU);
            cout << "Masukan Nama Voucher: "; cin >> namaV;
            A2 = findVc(L2, namaV);
            insertRelation(L1, L2, namaU, namaV);
            showUser(L1);
            cout<<"tekan enter";_getch();system("cls");break;
        default:
            cout << "Invalid Input." << endl;
            cout<<"Tekan enter";_getch();system("cls");break;
        }
    }

    return 0;
}
