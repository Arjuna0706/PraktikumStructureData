#ifndef SLL_H
#define SLL_H

typedef int infotype;

typedef struct elmlist* address;

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

void insertLast(List &L, address p);

void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
void deleteAfter(List &L, address prec, address &p);

void selectionSort(List &L);

void addNewElementList(List &L, int n);
void printInfo(List L);

#endif
