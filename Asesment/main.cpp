#include "DLL.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address p = nullptr;
 
    createList(L);
    tambahBarang_108072500059(L, "ultra_milk_125ml", 120, 2000);
    tambahBarang_108072500059(L, "aquviva_600ml", 25, 2700);
    tambahBarang_108072500059(L, "delfi_chocho_25gr", 3, 5000);
    tambahBarang_108072500059(L, "aquviva_600ml", 27, 3000);
    tambahBarang_108072500059(L, "taro_barbeque_78gr", 4, 8000);

    cout << "Barang yang ada" << endl;
    cout 
    printInfo(L);
    cout << endl;
    cout << "barang yg hrs restock" << endl;
    tampilRestock_108072500059(L);

    cout << endl;
    cout << "Potensi keuntungan: "
         << hitungKeuntungan_108072500059(L) << endl;

    deleteFirst(L, p);
    delete p;

    cout << endl;
    cout << "hapus barang terlama" << endl;
    printInfo(L);

    return 0;
}
