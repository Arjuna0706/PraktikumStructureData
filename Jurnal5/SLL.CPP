#include "SLL.h"
#include <iostream>
using namespace std;

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

    if (!isEmpty(L)) {
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
}

void deleteAfter(List &L, address prec, address &p) {
    p = nullptr;

    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void selectionSort(List &L) {
    address p, min, temp;
    infotype x;

    p = L.first;

    while (p != nullptr) {
        min = p;
        temp = p;

        while (temp != nullptr) {
            if (temp->info < min->info) {
                min = temp;
            }

            temp = temp->next;
        }

        x = p->info;
        p->info = min->info;
        min->info = x;

        p = p->next;
    }
}

void addNewElementList(List &L, int n) {
    int i;
    infotype x;
    address p;

    for (i = 0; i < n; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> x;

        p = allocate(x);
        insertLast(L, p);
    }
}

void printInfo(List L) {
    address p = L.first;

    if (isEmpty(L)) {
        cout << "List kosong" << endl;
    } else {
        while (p != nullptr) {
            cout << p->info;

            if (p->next != nullptr) {
                cout << ", ";
            }

            p = p->next;
        }

        cout << endl;
    }
}
