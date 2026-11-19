
#ifndef DLL_H
#define DLL_H

#include <string>
using namespace std;

struct infotype {
    string nama;
    int stok;
    int hargaBeli;
    int hargaJual;
};

typedef struct elmList* address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
bool isEmpty(List L);
address createElement(infotype x);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void insertAfter(List &L, address awal, address p);
void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
void deleteAfter(List &L, address awal, address &p);
void printInfo(List L);
void deleteAngka(List &L, int x);
void reverseList(List &L);
void tambahBarang_108072500059(List &L, string nama, int stok, int hargaBeli);
void tampilRestock_108072500059(List L);
int hitungKeuntungan_108072500059(List L);
#endif