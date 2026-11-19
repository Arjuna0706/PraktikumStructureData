#include "queue.h"
#include <iostream>

// Melepaskan sisa memori jika program berakhir sebelum semua dilayani.
void clearRemaining(Queue &Q) {
    while (!isEmpty(Q)) {
        address p;
        dequeue(Q, p);
        delete p;
    }
}

int main() {
    Queue Q;
    createQueue(Q);

    int banyakPasien;
    std::cout << "masukkan banyak pasien yang ingin di input: ";
    if (!(std::cin >> banyakPasien) || banyakPasien < 0) {
        std::cout << "Jumlah pasien tidak valid.\n";
        return 1;
    }

    for (int i = 1; i <= banyakPasien; ++i) {
        std::string nama, pekerjaan;
        int usia, nomorAntrean;
        std::cout << "\npasien ke-" << i << "\nnama: ";
        std::getline(std::cin >> std::ws, nama);
        std::cout << "usia: ";
        if (!(std::cin >> usia) || usia < 0) {
            std::cout << "Usia tidak valid.\n";
            clearRemaining(Q);
            return 1;
        }
        std::cout << "pekerjaan: ";
        std::getline(std::cin >> std::ws, pekerjaan);

        bool nomorValid;
        do {
            std::cout << "nomor antrean: ";
            if (!(std::cin >> nomorAntrean)) {
                std::cout << "Nomor antrean tidak valid.\n";
                clearRemaining(Q);
                return 1;
            }
            nomorValid = nomorAntrean > 0;
            for (address p = front(Q); p != nullptr; p = p->next) {
                if (p->info.nomorAntrean == nomorAntrean) {
                    nomorValid = false;
                }
            }
            if (!nomorValid) {
                std::cout << "Nomor harus positif dan belum digunakan.\n";
            }
        } while (!nomorValid);

        enqueue(Q, allocate(nama, usia, pekerjaan, nomorAntrean));
    }

    std::cout << "\nbanyak pasien dalam antrean: " << size(Q) << '\n';
    if (!isEmpty(Q)) {
        std::cout << "pasien paling depan: " << front(Q)->info.nama << '\n'
                  << "pasien paling belakang: " << back(Q)->info.nama << '\n';
    }

    // Alur 1.4.3: panggilan pertama melayani maksimal lima pasien.
    serveQueue(Q);

    if (!isEmpty(Q)) {
        int nomorDarurat;
        std::cout << "\nmasukkan nomor antrean yang ingin di prioritaskan: ";
        if (!(std::cin >> nomorDarurat)) {
            std::cout << "Nomor antrean tidak valid.\n";
            clearRemaining(Q);
            return 1;
        }

        // Alur 1.4.4: pindahkan pasien darurat, lalu layani batch kedua.
        emergencyHandle(Q, nomorDarurat);
        serveQueue(Q);
    }

    // Alur 1.4.5: promosikan pasien tersisa, lalu layani batch ketiga.
    reassignQueue(Q);
    std::cout << "\ndata prioritas pasien telah di update.\n";
    serveQueue(Q);

    std::cout << "\nsisa pasien dalam antrean: " << size(Q) << '\n';
    clearRemaining(Q);
    return 0;
}
