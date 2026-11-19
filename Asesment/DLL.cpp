#include "DLL.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(List L) {
    return L.first == nullptr && L.last == nullptr;
}

address createElement(infotype x) {
    address p = new elmList;
    p->info.nama = x.nama;
    p->info.stok = x.stok;
    p->info.hargaBeli = x.hargaBeli;
    p->info.hargaJual = x.hargaJual;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}


void insertFirst(List &L, address p) {
    if (p == nullptr) return;
    p->prev = nullptr;
    p->next = L.first;
    if (isEmpty(L)) {
        L.last = p;
    } else {
        L.first->prev = p;
    }
    L.first = p;
}

void insertLast(List &L, address p) {
    if (p == nullptr) return;
    p->next = nullptr;
    p->prev = L.last;
    if (isEmpty(L)) {
        L.first = p;
    } else {
        L.last->next = p;
    }
    L.last = p;
}

void insertAfter(List &L, address awal, address p) {
    if (awal == nullptr || p == nullptr) return;
    p->next = awal->next;
    p->prev = awal;
    if (awal->next != nullptr) {
        awal->next->prev = p;
    } else {
        L.last = p;
    }
    awal->next = p;
}

void deleteFirst(List &L, address &p) {
    p = nullptr;
    if (isEmpty(L)) return;
    p = L.first;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = p->next;
        L.first->prev = nullptr;
    }
    p->next = nullptr;
    p->prev = nullptr;
}

void deleteLast(List &L, address &p) {
    p = nullptr;
    if (isEmpty(L)) return;
    p = L.last;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = p->prev;
        L.last->next = nullptr;
    }
    p->next = nullptr;
    p->prev = nullptr;
}

void deleteAfter(List &L, address awal, address &p) {
    p = nullptr;
    if (isEmpty(L) || awal == nullptr ||
        awal->next == nullptr) {
        return;
    }

    p = awal->next;
    awal->next = p->next;
    if (p->next != nullptr) {
        p->next->prev = awal;
    } else {
        L.last = awal;
    }
    p->next = nullptr;
    p->prev = nullptr;
}

void printInfo(List L) {
    address p = L.first;

    if (isEmpty(L)) {
        cout << "List kosong" << endl;
        return;
    }
    while (p != nullptr) {
        cout << "Nama Item: " << p->info.nama << endl;
        cout << "Jumlah Stok: " << p->info.stok << endl;
        cout << "Harga Beli: " << p->info.hargaBeli << endl;
        cout << "Harga Jual: " << p->info.hargaJual << endl;
        cout << "  " << endl;

        p = p->next;
    }
}

void deleteAngka(List &L, int x) {
    address current = L.first;

    while (current != nullptr) {
        address next = current->next;
        if (current->info.stok == x) {
            address p = nullptr;
            if (current == L.first) {
                deleteFirst(L, p);
            } else if (current == L.last) {
                deleteLast(L, p);
            } else {
                deleteAfter(L, current->prev, p);
            }
            delete p;
        }
        current = next;
    }
}

void reverseList(List &L) {
    address p = L.first;
    while (p != nullptr) {
        address temp = p->next;

        p->next = p->prev;
        p->prev = temp;
        p = temp;
    }
    address temp = L.first;
    L.first = L.last;
    L.last = temp;
}


void tambahBarang_108072500059(List &L, string nama, int stok, int hargaBeli) {

    address p = L.first;

    while (p != nullptr) {
        if (p->info.nama == nama) {
            p->info.stok = p->info.stok + stok;
            p->info.hargaBeli = hargaBeli;
            p->info.hargaJual = hargaBeli + (hargaBeli * 20 / 100);
            return;
        }
        p = p->next;
    }
    infotype barang;

    barang.nama = nama;
    barang.stok = stok;
    barang.hargaBeli = hargaBeli;
    barang.hargaJual = hargaBeli + (hargaBeli * 20 / 100);

    address baru = createElement(barang);
    insertLast(L, baru);
}


void tampilRestock_108072500059(List L) {
    address p = L.first;

    while (p != nullptr) {
        if (p->info.stok < 5) {
            cout << "Nama Item: " << p->info.nama << endl;
            cout << "Jumlah Stok: " << p->info.stok << endl;
            cout << "Harga Beli: " << p->info.hargaBeli << endl;
            cout << "Harga Jual: " << p->info.hargaJual << endl;
            cout << "  " << endl;
        }

        p = p->next;
    }
}

int hitungKeuntungan_108072500059(List L) {
    int total = 0;
    address p = L.first;

    while (p != nullptr) {
        int keuntungan;
        keuntungan = (p->info.hargaJual - p->info.hargaBeli) * p->info.stok;
        total = total + keuntungan;
        p = p->next;
    }
    return total;
}
