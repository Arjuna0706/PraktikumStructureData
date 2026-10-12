#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotype {
    string username;
    string userid;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void createList(List &L);
address createNewElm(infotype akun);
void InsertLast(address p, List &L);
address findAkun(string username, List L);
void signUp(infotype akun, List &L);

void deleteFirst(List &L, address &p);
void deleteAfter(address q, address &p);
void deleteLast(List &L, address &p);
void removeAkun(string username, List &L);

void tampil(List L);

#endif 