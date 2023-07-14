#include <cstdio>

int main() {
  int maxd = 0, maxn = 0;
  int a, b;
  for (int i = 0; i < 7; i++) {
    scanf("%d %d", &a, &b);
    if (a + b > 8 && a + b > maxn) {
      maxd = i + 1;
      maxn = a + b;
    }
  }
  printf("%d", maxd);
  return 0;
}