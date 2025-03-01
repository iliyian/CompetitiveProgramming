#include <cstdio>

long long pow(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long t = a;
  for (int i = 1; i < b; i++) {
    t *= a;
  }
  return t;
}

int main() {
  int k, n, count = 0;
  long long res = 0;
  scanf("%d %d", &k, &n);
  while (n) {
    // printf("n=%d\n", n);
    // printf("%d^%d=%lld\n", k, count, pow(k, count));
    int a = n % 2;
    res += a * pow(k, count);
    // printf("res=%lld\n", res);
    count++;
    n >>= 1;
  }
  printf("%lld", res);
  return 0;
}