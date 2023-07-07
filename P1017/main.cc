#include <cstdio>

void transform(int n, int r) {
  if (n == 0) return;
  int m = n % r;
  if (m < 0) m -= r, n += r;

  if (m >= 10) m += 'A' - 10;
  else m += '0';
  transform(n / r, r);
  printf("%c", m);
}

int main() {
  int n, r;
  scanf("%d %d", &n ,&r);
  printf("%d=", n);
  transform(n, r);
  printf("(base%d)", r);
  return 0;
}