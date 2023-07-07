#include <cstdio>

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int x0, y0;
  scanf("%d %d", &x0, &y0);
  int mul = x0 * y0, res = 0;
  for (int i = x0; i <= mul / x0; i++) {
    int b = mul / i;
    if (x0 == gcd(i, b) && i * b == mul) {
      res ++;
      // printf("a=%d, b=%d\n", i, b);
    };
  }
  printf("%d", res);
  return 0;
}