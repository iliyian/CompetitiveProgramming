#include <cstdio>

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  printf("%d %d", b <= d ? c - a : c - a - 1, b <= d ? d - b : 60 - b + d);
  return 0;
}