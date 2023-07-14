#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int n1 = !(n % 2), n2 = (4 < n && n <= 12);
  printf("%d %d %d %d", n1 && n2, n1 || n2, (n1 && !n2) || (n2 && !n1), !n1 && !n2);
  // n1 | n2
  return 0;
}