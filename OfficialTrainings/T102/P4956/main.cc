#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  // 7x+21k = n / 52;
  int m = n / 52;
  for (int k = 1;; k++) {
    int x = (m - 21 * k) / 7;
    if ((m - 21 * k) % 7 == 0 && x <= 100) {
      printf("%d\n%d", x, k);
      break;
    }
  }
  return 0;
}