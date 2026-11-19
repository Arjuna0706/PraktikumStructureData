#ifndef QUEUE_H
#define QUEUE_H

#include <string>

struct elmqueue;
typedef elmqueue *address;

struct infotype {
    std::string nama;
    int usia;
    std::string pekerjaan;
    bool prioritas;
    int nomorAntrean;
};

struct Queue {
    address head;
    address tail;
};

struct elmqueue {
    infotype info;
    address next;
};

void createQueue(Queue &Q);
bool isEmpty(const Queue &Q);
address allocate(std::string nama, int usia, std::string pekerjaan,
                 int nomorAntrean);
address front(const Queue &Q);
address back(const Queue &Q);
void enqueue(Queue &Q, address p);
void dequeue(Queue &Q, address &p);
int size(const Queue &Q);
void printPatient(address p);
void serveQueue(Queue &Q);
void reassignQueue(Queue &Q);
void emergencyHandle(Queue &Q, int nomorAntrean);

#endif
