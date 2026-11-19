#include "queue.h"
#include <iostream>

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(const Queue &Q) {
    return Q.head == nullptr && Q.tail == nullptr;
}

address allocate(std::string nama, int usia, std::string pekerjaan,
                 int nomorAntrean) {
    address p = new elmqueue;
    p->info.nama = nama;
    p->info.usia = usia;
    p->info.pekerjaan = pekerjaan;
    p->info.prioritas = usia >= 60 || pekerjaan == "tenaga_kesehatan";
    p->info.nomorAntrean = nomorAntrean;
    p->next = nullptr;
    return p;
}

address front(const Queue &Q) {
    return Q.head;
}

address back(const Queue &Q) {
    return Q.tail;
}

void enqueue(Queue &Q, address p) {
    // p harus berupa satu node yang belum berada dalam queue mana pun.
    if (p == nullptr) {
        return;
    }
    p->next = nullptr;

    if (isEmpty(Q)) {
        Q.head = p;
        Q.tail = p;
    } else if (!p->info.prioritas || Q.tail->info.prioritas) {
        Q.tail->next = p;
        Q.tail = p;
    } else if (!Q.head->info.prioritas) {
        p->next = Q.head;
        Q.head = p;
    } else {
        // Sisipkan setelah pasien prioritas terakhir agar tetap FIFO.
        address temp = Q.head;
        while (temp->next != nullptr && temp->next->info.prioritas) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

void dequeue(Queue &Q, address &p) {
    p = nullptr;
    if (!isEmpty(Q)) {
        p = Q.head;
        Q.head = p->next;
        if (Q.head == nullptr) {
            Q.tail = nullptr;
        }
        p->next = nullptr;
    }
}

int size(const Queue &Q) {
    int count = 0;
    for (address p = Q.head; p != nullptr; p = p->next) {
        ++count;
    }
    return count;
}

void printPatient(address p) {
    if (p == nullptr) {
        return;
    }
    std::cout << "------------------------------\n"
              << "nama: " << p->info.nama << '\n'
              << "usia: " << p->info.usia << '\n'
              << "pekerjaan: " << p->info.pekerjaan << '\n'
              << "prioritas: " << p->info.prioritas << '\n'
              << "nomor antrean: " << p->info.nomorAntrean << '\n';
}

void serveQueue(Queue &Q) {
    int dilayani = 0;
    while (!isEmpty(Q) && dilayani < 5) {
        address p;
        dequeue(Q, p);
        printPatient(p);
        std::cout << "Vaksinasi berhasil.\n";
        delete p;
        ++dilayani;
    }
}

void reassignQueue(Queue &Q) {
    // Semua pasien yang tersisa menjadi prioritas, urutan tetap sama.
    for (address p = Q.head; p != nullptr; p = p->next) {
        p->info.prioritas = true;
    }
}

void emergencyHandle(Queue &Q, int nomorAntrean) {
    address prev = nullptr;
    address p = Q.head;
    while (p != nullptr && p->info.nomorAntrean != nomorAntrean) {
        prev = p;
        p = p->next;
    }
    if (p == nullptr) {
        return; // Nomor tidak ditemukan: antrean tetap.
    }

    p->info.prioritas = true;
    if (p == Q.head) {
        return;
    }

    // Lepaskan node dari posisi awal sebelum memindahkannya ke depan.
    prev->next = p->next;
    if (p == Q.tail) {
        Q.tail = prev;
    }
    p->next = Q.head;
    Q.head = p;
}
