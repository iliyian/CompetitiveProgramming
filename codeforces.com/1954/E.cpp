// date: 2024-07-28 12:25:08
// tag: 数论分块
// long long在除法多的情况下疑似比int慢一倍

#include <bits/stdc++.h>
// using namespace std;

constexpr int N = 1e5 + 5;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int maxn = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    maxn = std::max(maxn, a[i]);
  }
  std::vector<long long> ans(maxn + 2);
  for (int k = 0; k < n; k++) {
    for (int i = 1, j;; i = j + 1) {
      j = std::min(i < a[k] ? (a[k] - 1) / ((a[k] - 1) / i) : maxn,
        i < a[k + 1] ? (a[k + 1] - 1) / ((a[k + 1] - 1) / i) : maxn);
      if (j == maxn) break;
      int x = (a[k + 1] - 1) / i - std::max(0, (a[k] - 1) / i); // a[0]=0
      if (x > 0) {
        ans[i] += x , ans[j + 1] -= x;
      }
    }
  }
  for (int i = 1; i <= maxn; i++) {
    ans[i] += ans[i - 1];
    std::cout << ans[i] + 1 << ' ';
  }
  std::cout << '\n';

  return 0;
}