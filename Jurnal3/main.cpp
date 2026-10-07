#include "provinsi.h"

void buatProvinsi(Provinsi &prov) {
    cin >> prov.nama;
    cin >> prov.ibukota;

    prov.nKota = 0;
    prov.nKab = 0;
}

void tambahDaerah(Provinsi &prov, bool flag) {
    string daerah;
    cin >> daerah;

    if (flag == true) {
        prov.kota[prov.nKota] = daerah;
        prov.nKota++;
    } else {
        prov.kabupaten[prov.nKab] = daerah;
        prov.nKab++;
    }
}

void tampilProvinsi(Provinsi &prov) {
    cout << "Nama Provinsi: " << prov.nama << endl;
    cout << "Banyaknya Kota dan Kabupaten dari Ibu Kota "
         << prov.ibukota
         << " adalah "
         << prov.nKota + prov.nKab
         << endl;
}