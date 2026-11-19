#include <iostream>
#include "../stack.h"
using namespace std;

int main() {
    stack S;
    infotype x;

    createStack(S);

    for (int i = 1; i <= MAXSTACK; i++) {
        cout << "input angka ke-" << i << ": ";
        cin >> x;
        push(S, x);
    }
    if (isFull(S)) {
        cout << "stack sudah penuh!" << endl;
    }
    cout << endl;
    cout << "hasil penjumlahan elemen yang genap dalam stack: "
         << sumGenap(S) << endl;

    return 0;
}