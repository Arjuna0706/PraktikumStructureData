#ifndef provinsi.h
#define provinsi.h
#include <iostream>
#include <string>

using namespace std;

struct Provinsi {
    string nama;
    string ibukota;
    string kota[20];
    string kabupaten[20];
    int nKota;
    int nKab;
};

void buatProvinsi(Provinsi &prov);
void tambahDaerah(Provinsi &prov, bool flag);
void tampilProvinsi(Provinsi &prov);

#endif