#include <cstdio>

int main() {
  int m, t, s;
  scanf("%d %d %d", &m, &t, &s);
  if (t == 0) printf("0");
  else {
    int r = m - ((s - 1) / t + 1);
    printf("%d", r < 0 ? 0 : r);
  }
  return 0;
}