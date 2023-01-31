#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "struct.h"

using namespace std;

int main() {
    char y;
    int pilihan;

        menu:
        system("cls");
        cout << " ____________________________________________" << endl;
        cout << " |****** MENU PERPUSTAKAAN GEMAR BACA ******|  " << endl;
        cout << " |__________________________________________|" << endl;
        cout << " |1 | Tambah Buku                          ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |2 | Ubah Buku                            ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |3 | Hapus Buku                           ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |4 | Peminjaman Buku                      || " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |5 | Tampilkan Seluruh Data Buku          ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |6 | Daftar Peminjam Buku                 ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |7 | Daftar Buku Yang Dipinjam            ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |8 | Daftar Seseorang Meminjam Buku       ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << " |9 | Cari Sebuah Buku                     ||  " << endl;
        cout << " |__|______________________________________||" << endl;
        cout << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambah:
                tambahBuku();
                cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>y;

                if(y=='y'||y=='Y'){

				goto tambah;
                }else{
                    cout << "\n\n Data Berhasil Disimpan \n" << endl;
                    system("pause");
                    system("cls");
                    goto menu;
                }
                break;

            case 2:
                ubah:
                ubahBuku();
                cout<<"Apakah Anda Ingin Mengubah Data Lagi ? (y/n) :";cin>>y;
                if(y=='y'||y=='Y'){
				goto ubah;
                }else{
                    cout << "\n Data Berhasil Disimpan \n" << endl;
                    system("pause");
                    system("cls");
                    goto menu;
                }
                break;

            case 3:
                hapus:
                hapusBuku();
                break;
                cout<<"Apakah Anda Ingin Menghapus Data Lagi ? (y/n) :";cin>>y;
                if(y=='y'||y=='Y'){
				goto hapus;
                }else{
                    cout << "\n Data Berhasil Disimpan \n" << endl;
                    system("pause");
                    system("cls");
                    goto menu;
                }

            case 4:
                pinjam:
                lihatBuku();
                cout << endl << endl;
                pinjamBuku();
                cout<<"Apakah Anda Ingin pinjam Lagi ? (y/n) :";cin>>y;
                if(y=='y'||y=='Y'){
				goto pinjam;
                }else{
                    cout << "\n Data Berhasil Disimpan \n" << endl;
                    system("pause");
                    system("cls");
                    goto menu;
                }
                break;

            case 5:
                lihatBuku();
                system("pause");
                system("cls");
				goto menu;
                break;

            case 6:
                lihatPeminjamBuku();
                system("pause");
                system("cls");
				goto menu;
                break;

            case 7:
                lihatBukuDipinjam();
                system("pause");
                system("cls");
				goto menu;
                break;

            case 8:
                tampilkanPeminjamanPeminjam();
                system("pause");
                system("cls");
				goto menu;
                break;

            case 9:
                cari:
                cariBuku();
                cout<<"Apakah Anda Ingin mencari buku lagi ? (y/n) :";cin>>y;
                if(y=='y'||y=='Y'){
				goto cari;
                }else{
                    cout << "\n Data Berhasil Disimpan \n" << endl;
                    system("pause");
                    system("cls");
                    goto menu;
                }
                break;

            default:
                cout << "Tidak ada pilihan untuk angka tersebut" << endl;
                cout<<"Apakah Anda Ingin kembali ke menu ? (y/n) :\t";cin>>y;
                if(y=='y'||y=='Y'){
                system("cls");
                goto menu;
                }

        }
    cout << endl << "Terima Kasih sudah mengunjungi perpustakaan kami";
    return 0;
}
