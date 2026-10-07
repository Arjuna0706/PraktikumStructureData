#include <iostream>
using namespace std;

float hitungKekauatan(int fisik, int sihir, int pertahanan){
    float total;
    total = (2 * fisik) + (3 * sihir) - (0.5 * pertahanan);
    return total;
}


int main() {
    int n;
    int fisik, sihir, pertahanan;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> fisik >> sihir >> pertahanan;
        float total = hitungKekauatan(fisik, sihir, pertahanan);
        printf("Total kekuatan petualang %d: %.1f\n", i, total);
    }

    return 0;
}