#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S) {
    S.top = 0;
}

bool isEmpty(stack S) {
    return S.top == 0;
}


bool isFull(stack S) {
    return S.top == MAXSTACK;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[S.top] = x;
        S.top++;
    }
}

infotype pop(stack &S) {
    if (!isEmpty(S)) {
        S.top--;
        return S.info[S.top];
    }

    return 0;
}

int sumGenap(stack S) {
    int total = 0;

    for (int i = 0; i < S.top; i++) {
        if (S.info[i] % 2 == 0) {
            total += S.info[i];
        }
    }

    return total;
}

void reverseStack(stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;

    while (kiri < kanan) {
        infotype temp = S.info[kiri];

        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;

        kiri++;
        kanan--;
    }
}
void printInfo(stack S) {
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << ", ";
    }

    cout << endl;
}