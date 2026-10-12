#include "sll.h"

int main() {
    List L;
    createList(L);

    int pilih;
    infotype akun;
    string nama;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Sign up" << endl;
        cout << "2. Remove akun" << endl;
        cout << "3. Tampil list" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Username: ";
            cin >> akun.username;
            cout << "Userid  : ";
            cin >> akun.userid;
            signUp(akun, L);
        } else if (pilih == 2) {
            cout << "Username yang dihapus: ";
            cin >> nama;
            removeAkun(nama, L);
        } else if (pilih == 3) {
            tampil(L);
        }
    } while (pilih != 0);

    return 0;
}