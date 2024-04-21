#include <cstdio>
#include <cmath>

// void print(int i, int n, int a) {
//   if ()
// }

int main() {
  // freopen("data.out", "w", stdout);
  // freopen("data.in", "r", stdin);

  int n;
  scanf("%d", &n);
  for (int i = n; i >= 0; i--) {
    int a;
    scanf("%d", &a);
    if (i == n && a == 0) n--;
    if (!a) continue;
    if (i != n && a > 0) printf("+");
    if (abs(a) > 1 || i == 0) printf("%d", a);
    if (a == -1 && i) printf("-");
    if (i > 1) printf("x^%d", i);
    if (i == 1) printf("x");
  }
  return 0;
}