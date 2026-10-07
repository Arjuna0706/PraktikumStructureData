#include "SLL.h"

void createList(List &L) {
    L.first = nullptr;
}

bool isEmpty(List L) {
    return L.first == nullptr;
}

address allocate(infotype x) {
    address p = new elmlist;
    p->info = x;
    p->next = nullptr;
    return p;
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(List &L, address p) {
    if (isEmpty(L)) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void deleteFirst(List &L, address &p) {
    p = nullptr;
    if (!isEmpty(L)) {
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}

void deleteLast(List &L, address &p) {
    p = nullptr;
    if (isEmpty(L)) return;
    if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        address q = L.first;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

void deleteAfter(List &L, address prec, address &p) {
    p = nullptr;
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void insertAfter(List &L, address prec, address p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "Daftar produk kosong";
    } else {
        address p = L.first;
        while (p != nullptr) {
            cout << p->info;
            if (p->next != nullptr) cout << ", ";
            p = p->next;
        }
    }
}

address findInfo(List L, infotype x) {
    address p = L.first;
    while (p != nullptr) {
        if (p->info == x) return p;
        p = p->next;
    }
    return nullptr;
}