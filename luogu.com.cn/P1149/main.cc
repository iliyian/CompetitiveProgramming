#include <cstdio>
int map[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int matches(int n) {
  int res = 0;
  while (n >= 10) {
    res += map[n % 10];
    n /= 10;
  }
  res += map[n];
  // printf("%d: %d\n", n, res);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 4) {
    printf("0");
    return 0;
  }

  int res = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (matches(i) + matches(j) + matches(i+j) == n-4) {
        // printf("%d+%d=%d\n", i, j, i+j);
        res ++;
      }
    }
  }
  printf("%d", res);
  return 0;
}