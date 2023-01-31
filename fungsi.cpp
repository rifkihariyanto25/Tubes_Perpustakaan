#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "struct.h"

// deklarasi
vector<Buku> daftarBuku;
vector<Peminjaman> daftarPeminjaman;
using namespace std;

// Fungsi untuk menambah buku
void tambahBuku() {
    Buku buku;
    cout << "Masukkan ISBN : ";
    cin >> buku.ISBN;
    cout << "Masukkan Judul Buku : ";
    cin.ignore();
    getline(cin, buku.judul);
    cout << "Masukkan Penulis Buku : ";
    getline(cin, buku.penulis);
    cout << "Masukkan Tahun Terbit Buku : ";
    cin >> buku.tahunterbit;
    cout << "Masukan Penerbit Buku : ";
    cin.ignore();
    getline(cin, buku.penerbit);
    daftarBuku.push_back(buku);
    cout << "Buku berhasil ditambahkan!" << endl;
}

void ubahBuku() {

    string ISBN;
    cout << "Masukkan ISBN buku yang akan diubah: ";
    cin >> ISBN;
    bool ketemu = false;
    for (int i = 0; i < daftarBuku.size(); i++) {
        if (daftarBuku[i].ISBN == ISBN) {
            ketemu = true;
            cout << "Masukkan judul buku baru: ";
            cin.ignore();
            getline(cin, daftarBuku[i].judul);
            cout << "Masukkan penulis buku baru: ";
            getline(cin, daftarBuku[i].penulis);
            cout << "Masukkan tahun terbit baru: ";
            cin >> daftarBuku[i].tahunterbit;
            cout << "Masukkan penerbit baru: ";
            cin.ignore();
            getline(cin, daftarBuku[i].penerbit);
            cout << "Buku berhasil diubah." << endl;

        }
    }if(!ketemu) {
            cout << "Buku tidak ditemukan!" << endl;
        }
}

// untuk menghapus buku
void hapusBuku() {
    string ISBN;
    cout << "Masukkan ISBN buku yang akan dihapus: ";
    cin >> ISBN;
    bool ketemu = false;
    for (int i = 0; i < daftarBuku.size(); i++) {
        if (daftarBuku[i].ISBN == ISBN) {
            ketemu = true;
            daftarBuku.erase(daftarBuku.begin() + i);
            cout << "Buku berhasil dihapus!" << endl;
            break;
        }

    }if(!ketemu) {
            cout << "Buku tidak ditemukan!" << endl;
        }

}



// Fungsi untuk melakukan peminjaman buku

void pinjamBuku() {
    string idBuku;
    int total;
    cout << "Masukkan ISBN Buku yang akan dipinjam: ";
    cin >> idBuku;
    bool ketemu = false;
    for (int i = 0; i < daftarBuku.size(); i++) {
        if (daftarBuku[i].ISBN == idBuku) {
            ketemu = true;
            Peminjaman peminjaman;
            peminjaman.idBuku = daftarBuku[i].ISBN;
            cout << "Masukkan Nama Peminjam: ";
            cin.ignore();
            getline(cin, peminjaman.namaPeminjam);
            cout << "Masukkan Waktu Pinjam (DDMMYYYY): ";
            cin >> peminjaman.waktuPinjam;
            cout << "Masukkan Waktu Kembali (DDMMYYYY): ";
            cin >> peminjaman.waktuKembali;
            total = (peminjaman.waktuKembali - peminjaman.waktuPinjam)/10000000;
            cout<<"Lama Pinjaman:"<<total<<" Hari"<<endl;
            daftarPeminjaman.push_back(peminjaman);
            cout << "Buku berhasil dipinjam!" << endl;
            break;
        }
    }if(!ketemu) {
            cout << "Buku tidak ditemukan!" << endl;
        }


}


// Fungsi untuk menampilkan seluruh baris data buku
void lihatBukuFile() {
    cout << " Daftar Buku:" << endl;
    cout<<"------------------------------------------------------\n";
    cout << " ISBN\t Judul\t Penulis\tTahun Terbit\t Penerbit" << endl;
    cout<<"------------------------------------------------------\n";
    cout << endl;
     string daftarBuku;
        ifstream buku_file("buku.txt");
        while (getline(buku_file, daftarBuku))
        {
            cout << daftarBuku << endl;
        }
}

void lihatBuku(){
    cout << " Daftar Buku:" << endl;
    cout<<"-------------------------------------------------------\n";
    cout << " ISBN\t Judul\t  Penulis\t Tahun Terbit\t Penerbit" << endl;
    cout<<"-------------------------------------------------------\n";
    cout<< endl;
        for (int i = 0; i < daftarBuku.size(); i++) {
        cout
        << daftarBuku[i].ISBN << "\t"
        << daftarBuku[i].judul << "\t"
        << daftarBuku[i].penulis << "\t"
        << daftarBuku[i].tahunterbit << "\t"
        << daftarBuku[i].penerbit << "\t" << endl;
    cout<<"-------------------------------------------------------\n";
    cout << endl;

    }
}

// Fungsi untuk menampilkan seluruh baris data peminjaman buku
void lihatPeminjamBuku() {
    cout << "Daftar Peminjaman:" << endl;
    for (int i = 0; i < daftarPeminjaman.size(); i++) {
        cout<<"---------------------------------------------------\n";
        cout << " ISBN\t Peminjam\t Waktu Pinjam\t Waktu Kembali" << endl;
        cout
        << daftarPeminjaman[i].idBuku << "\t"
        << daftarPeminjaman[i].namaPeminjam << "\t"
        << daftarPeminjaman[i].waktuPinjam << "\t"
        << daftarPeminjaman[i].waktuKembali << endl;
        cout<<"---------------------------------------------------\n";
        cout << endl;

    }
}




// Fungsi untuk menampilkan seluruh buku yang dipinjam oleh salah satu peminjam
void lihatBukuDipinjam() {
    string namaPeminjam;
    cout << "Masukkan Nama Peminjam: ";
    cin >> namaPeminjam;
    bool found = false;
    for (int i = 0; i < daftarPeminjaman.size(); i++) {
        if (daftarPeminjaman[i].namaPeminjam == namaPeminjam) {
            found = true;
            for (int j = 0; j < daftarBuku.size(); j++) {
                if (daftarBuku[j].ISBN == daftarPeminjaman[i].idBuku) {
                    cout<<"---------------------------------------------------\n";
                    cout << "\tJudul" << endl;
                    cout << daftarBuku[j].judul << "\t" << endl;
                    cout<<"---------------------------------------------------\n";
                    cout << endl;
                    break;
                }
            }
        }
    }
        cout << "Peminjam tidak ditemukan!" << endl;
}


// Fungsi untuk menampilkan data peminjaman buku oleh peminjam tertentu
void tampilkanPeminjamanPeminjam() {
    string namaPeminjam;
    cout << "Masukkan Nama Peminjam : ";
    cin.ignore();
    getline(cin, namaPeminjam);

    vector<Peminjaman> peminjamanPeminjam;
    for (int i = 0; i < daftarPeminjaman.size(); i++) {
        if (daftarPeminjaman[i].namaPeminjam == namaPeminjam) {
            peminjamanPeminjam.push_back(daftarPeminjaman[i]);
        }
    }

    // Sorting data peminjaman
    for (int i = 0; i < peminjamanPeminjam.size() - 1; i++) {
        for (int j = 0; j < peminjamanPeminjam.size() - i - 1; j++) {
            if (peminjamanPeminjam[j].waktuPinjam > peminjamanPeminjam[j + 1].waktuPinjam) {
                swap(peminjamanPeminjam[j], peminjamanPeminjam[j + 1]);
            }
        }
    }

    cout << "Data Peminjaman Buku oleh " << namaPeminjam << " :" << endl;
    for (int i = 0; i < peminjamanPeminjam.size(); i++) {
        cout << "-------------------------------------------------------------\n";
        cout << "| ISBN Buku       |" << peminjamanPeminjam[i].idBuku << "     |" << endl;
        cout << "| Waktu Pinjam  | " << peminjamanPeminjam[i].waktuPinjam <<"|" << endl;
        cout << "| Waktu Kembali | " << peminjamanPeminjam[i].waktuKembali<<"|" << endl;
        cout << "-------------------------------------------------------------\n";
        cout << endl;
    }
}


// Mencari buku menggunakan keyword tertentu
void cariBuku() {
    string cari;
    cout << "Masukkan Buku yang akan di cari: ";
    cin.ignore();
    getline(cin, cari);

    cout << "Hasil Pencarian Buku:" << endl;
    cout<<"---------------------------------------------------\n";
    cout << "ISBN\t Judul\t Penulis\t Tahun Terbit\t Penerbit" << endl;
    cout<<"---------------------------------------------------\n";
    // Binary Search
    int low = 0;
    int high = daftarBuku.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (daftarBuku[mid].judul == cari) {
            cout << daftarBuku[mid].ISBN << "\t"
            << daftarBuku[mid].judul << "\t"
            << daftarBuku[mid].penulis << "\t"
            << daftarBuku[mid].tahunterbit << "\t\t"
            << daftarBuku[mid].penerbit << endl;
    cout<<"---------------------------------------------------\n";
    cout << endl;
            break;
        } else if (daftarBuku[mid].judul > cari) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}




