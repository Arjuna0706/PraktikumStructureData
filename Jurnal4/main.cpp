
#include "SLL.h"

int main() {
    List L;
    createList(L);

    for (int i = 1; i <= 5; i++) {
        string nama;
        cout << "Masukkan nama produk ke-" << i << ": ";
        getline(cin, nama);
        insertLast(L, allocate(nama));
    }
    cout << "Daftar produk: ";
    printInfo(L);
    cout << endl << endl;


    if (!isEmpty(L)) {
        string cari;
        cout << "Masukkan nama produk yang ingin dicari: ";
        getline(cin, cari);
        address hasil = findInfo(L, cari);
        if (hasil != nullptr) {
            cout << "Produk ditemukan pada alamat " << hasil << endl;
        } else {
            cout << "produk gada bang :<" << endl;
        }
    }
    cout << endl;


    cout << "Daftar awal produk: ";
    printInfo(L);
    cout << endl;

    while (!isEmpty(L)) {
        string lokasi;
        address p = nullptr;
        cout << "Lokasi produk yang dihapus (depan/belakang)? ";
        getline(cin, lokasi);

        if (lokasi == "depan") {
            deleteFirst(L, p);
        } else if (lokasi == "belakang") {
            deleteLast(L, p);
        } else {
            cout << "gabisa harus depan atau belakang." << endl;
            continue;
        }
        delete p;

        cout << "hasil: ";
        printInfo(L);
        cout << endl;
    }

    cout << "SELESAI" << endl;
    return 0;
}