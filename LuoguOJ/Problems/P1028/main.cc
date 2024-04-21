#include <cstdio>
#include <cstring>

// solve(n) == solve(n-1)

// int solve(int n) {
//   if (n / 2 == 0) return 1;
//   int sum = 1;
//   for (int i = 1; i <= n / 2; i++) {
//     sum += solve(i);
//   }
//   return sum;
// }

int main() {
  int n, ans[1001];
  scanf("%d", &n);

  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    ans[i] = 1;
    for (int j = 1; j <= i / 2; j++)
      ans[i] += ans[j];
  }
  printf("%d", ans[n]);
  return 0;
}