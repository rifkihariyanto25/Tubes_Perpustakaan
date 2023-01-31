#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

using namespace std;

struct Buku {
    string ISBN;
    string judul;
    string penulis;
    int tahunterbit;
    string penerbit;
};

struct Peminjaman {
    string idBuku;
    string namaPeminjam;
    int waktuPinjam;
    int waktuKembali;
};

void tambahBuku();
void ubahBuku();
void hapusBuku();
void lihatBuku();
void pinjamBuku();
void lihatPeminjamBuku();
void lihatBukuDipinjam();
void tampilkanPeminjamanPeminjam();
void cariBuku();

#endif


