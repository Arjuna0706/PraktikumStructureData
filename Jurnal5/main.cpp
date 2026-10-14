
#include "SLL.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address p;
    int n;

    createList(L);

    cout << "=== PROGRAM SINGLY LINKED LIST ===" << endl;

    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    addNewElementList(L, n);

    cout << "\nList sebelum diurutkan: ";
    printInfo(L);

    selectionSort(L);

    cout << "List setelah diurutkan: ";
    printInfo(L);

    deleteFirst(L, p);

    cout << "\nSetelah deleteFirst: ";
    printInfo(L);

    if (p != nullptr) {
        delete p;
    }

    deleteLast(L, p);

    cout << "Setelah deleteLast: ";
    printInfo(L);

    if (p != nullptr) {
        delete p;
    }

    if (!isEmpty(L)) {
        deleteAfter(L, L.first, p);

        cout << "Setelah deleteAfter: ";
        printInfo(L);

        if (p != nullptr) {
            delete p;
        }
    }

    while (!isEmpty(L)) {
        deleteFirst(L, p);
        delete p;
    }

    return 0;
}
