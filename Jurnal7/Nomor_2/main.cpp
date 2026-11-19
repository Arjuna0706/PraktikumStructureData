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
    cout << "elemen dalam stack sebelum dibalik: ";
    printInfo(S);
    cout << endl;
    reverseStack(S);
    cout << "urutan elemen dalam stack telah dibalik!" << endl;
    cout << endl;
    cout << "elemen dalam stack setelah dibalik: ";
    printInfo(S);
    return 0;
}