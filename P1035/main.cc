#include <cstdio>

int main() {
  int k;
  scanf("%d", &k);

  double sum = 0.0;
  for (double i = 1;; i++) {
    sum += 1 / i;
    if (sum > k) {
      printf("%d", (int)i);
      break;
    }
  }
  return 0;
}