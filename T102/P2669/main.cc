#include <cstdio>

int main() {
  int k;
  scanf("%d", &k);
  int rest = 1, ans = 0, round = 1;
  for (int i = 0; i < k; i++) {
    if (!rest) rest = ++round;
    ans += round;
    rest--;
  }
  printf("%d", ans);
  return 0;
}