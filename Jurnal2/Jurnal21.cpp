#include <iostream>
using namespace std;

int main() {
    int P[100];
    int n = 0;
    int angka;

    while (true) {
        cin >> angka;
        if (angka == 0) {
            break;
        }

        P[n] = angka;
        n++;
    }

    for (int i = 0; i < n; i++) {
        int puluhan = P[i] / 10;
        int satuan = P[i] % 10;

        if ((puluhan + satuan) % 2 == 0) {
            cout << (P[i]);
        }
    }
    return 0;
}