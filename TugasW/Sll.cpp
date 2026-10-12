#include "sll.h"

void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address createNewElm(infotype akun) {
    address p = new ElmList;
    if (p != NULL) {
        p->info = akun;
        p->prev = NULL;
        p->next = NULL;
    }
    return p;
}

void InsertLast(address p, List &L) {
    p->prev = L.Last;
    L.Last->next = p;
    L.Last = p;
}

address findAkun(string username, List L) {
    address p = L.First;
    while (p != NULL) {
        if (p->info.username == username) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void signUp(infotype akun, List &L) {
    address p;
    if (findAkun(akun.username, L) != NULL) {
        cout << "Account has been registered." << endl;
    } else {
        p = createNewElm(akun);
        if (p != NULL) {
            if (L.First == NULL) {
                L.First = p;
                L.Last = p;
            } else {
                InsertLast(p, L);
            }
        } else {
            cout << "Alokasi gagal." << endl;
        }
    }
}

void deleteFirst(List &L, address &p) {
    p = L.First;
    L.First = p->next;
    p->next = NULL;
    L.First->prev = NULL;
}

void deleteAfter(address q, address &p) {
    p = q->next;
    q->next = p->next;
    p->next->prev = q;
    p->prev = NULL;
    p->next = NULL;
}

void deleteLast(List &L, address &p) {
    p = L.Last;
    L.Last = p->prev;
    p->prev = NULL;
    L.Last->next = NULL;
}

void removeAkun(string username, List &L) {
    address p, q;
    p = findAkun(username, L);
    if (p != NULL) {
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            if (p == L.First) {
                deleteFirst(L, p);
            } else {
                if (p == L.Last) {
                    deleteLast(L, p);
                } else {
                    q = p->prev;
                    if (q == L.First) {
                        q->next = p->next;
                        p->next->prev = q;
                        p->prev = NULL;
                        p->next = NULL;
                    } else {
                        deleteAfter(q, p);
                    }
                }
            }
        }
        delete p;
    } else {
        cout << "Akun tidak ditemukan." << endl;
    }
}

void tampil(List L) {
    address p = L.First;
    if (p == NULL) {
        cout << "List kosong" << endl;
    }
    while (p != NULL) {
        cout << p->info.username << " (" << p->info.userid << ")";
        if (p->next != NULL) {
            cout << " <-> ";
        }
        p = p->next;
    }
    cout << endl;
}