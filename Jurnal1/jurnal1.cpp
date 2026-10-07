#include <iostream>
using namespace std;

int main() {
    int num;
    int p = 0;
    int n = 0;

    while (cin >> num && num != 0)
        if (num < 0 ) {
            n++;
        }else {
            p++;
        }

    if (n > p) {
        cout << n << " " << p << " negatif";
    } 
    else if (p > n) {
        cout << n << " " << p << " positif";
    } 
    else {
        cout << n << " " << p << " imbang";
    }

    return 0;
}