#include <iostream>
using namespace std;

int main() {
    int num;
    bool prima = true;

    cin >> num;

    for (int i = 2; i < num; i++) {
    if (num % i == 0) {
        prima = false;
        break;
    }
}

if (prima){
    cout << "prima";
}else {
    cout << "bukan prima";
}
}