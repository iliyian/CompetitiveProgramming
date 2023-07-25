#include <cstdio>

int main() {
    int n;
    double prize = 0;
    scanf("%d", &n);
    if (n > 400) {
        prize = 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663;
    } else if (150 < n && n <= 400) {
        prize = 150 * 0.4463 + (n - 150) * 0.4663;
    } else {
        prize = n * 0.4463;
    }
    printf("%.1f", prize);
    return 0;
}