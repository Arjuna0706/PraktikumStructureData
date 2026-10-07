#include <iostream>
using namespace std;

int main(){
int num;
cin >> num;

int jumlah = 0;

for (int i = 1; i < num; i++) {
    if (num % i == 0) {
        jumlah += i;
    }
}

if (jumlah == num) {
    cout << "sempurna";
} else {
    cout << "tidak sempurna";
}
}