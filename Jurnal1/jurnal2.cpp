#include <iostream>
using namespace std;

int main() {
    int num;
    int genap = 0;
    int terbesar = 0;

    while (cin >> num && num != 0) {

        if (num % 2 == 0) {
            genap++;

            if (num > terbesar) {
                terbesar = num;
            }
        }
    }

    cout << genap << " " << terbesar << endl;

    return 0;
}