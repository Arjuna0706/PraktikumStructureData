#ifndef SLL_H
#define SLL_H

#include <iostream>
#include <string>
using namespace std;

typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
bool isEmpty(List L);
address allocate(infotype x);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void insertAfter(List &L, address prec, address p);
void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
void deleteAfter(List &L, address prec, address &p);
void printInfo(List L);
address findInfo(List L, infotype x);

#endif