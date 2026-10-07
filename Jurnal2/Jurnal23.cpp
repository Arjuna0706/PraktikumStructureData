#include <iostream>

using namespace std;

void Hitung(int kecepatan, int energi, int ketelitian, int nomor) {
    float total;
    total = (3 * kecepatan) + (4 * energi) - (2 * ketelitian);
    printf("Total efisiensi robot %d: %.1f\n", nomor, total);
}

int main() {
    int n;
    int kecepatan, energi, ketelitian;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> kecepatan >> energi >> ketelitian;
        Hitung(kecepatan, energi, ketelitian, i);
    }

    return 0;
}