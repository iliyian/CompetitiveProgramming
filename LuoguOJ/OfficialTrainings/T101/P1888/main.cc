#include <cstdio>
#include <algorithm>

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a[3];
    scanf("%d %d %d", a, a+1, a+2);
    std::sort(a, a+3);
    int g = gcd(a[0], a[2]);
    printf("%d/%d", a[0] / g, a[2] / g);
    return 0;
}