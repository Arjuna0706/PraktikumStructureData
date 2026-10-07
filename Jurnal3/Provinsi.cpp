#include <iostream>
#include "provinsi.h"

using namespace std;

int main() {
    Provinsi prov[5];

    for (int i = 0; i < 5; i++) {
        cout << "Nama Provinsi : ";
        cin >> prov[i].nama;

        cout << "Ibu Kota      : ";
        cin >> prov[i].ibukota;

        prov[i].nKota = 0;
        prov[i].nKab = 0;
    }

    cout << "\nDaerah Jawa Barat" << endl;
    cout << "Kota       : ";
    tambahDaerah(prov[0], true);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[0], false);
    cout << "Kota       : ";
    tambahDaerah(prov[0], true);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[0], false);


    cout << "\nDaerah Jambi" << endl;
    cout << "Kota       : ";
    tambahDaerah(prov[1], true);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[1], false);


    cout << "\nDaerah Sumatera Barat" << endl;
    cout << "Kota       : ";
    tambahDaerah(prov[2], true);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[2], false);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[2], false);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[2], false);
    cout << "Kota       : ";
    tambahDaerah(prov[2], true);

    cout << "\nDaerah Yogyakarta" << endl;
    cout << "Kabupaten  : ";
    tambahDaerah(prov[3], false);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[3], false);
    cout << "Kabupaten  : ";
    tambahDaerah(prov[3], false);

    cout << "\nDaerah Jawa timur" << endl;

    cout << "\noutput" << endl;

    for (int i = 0; i < 4; i++) {
        tampilProvinsi(prov[i]);
        cout << endl;
    }

    return 0;
}