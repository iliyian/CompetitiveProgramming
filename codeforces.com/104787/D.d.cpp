#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 2e5, m = 2e5;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % (int)1e9 + 1 << ' ';
  }
  for (int i = 1; i <= m; i++) {
    std::cout << rd() % n + 1 << ' ' << rd() % (int)1e9 + 1 << '\n';
  }
}

signed main() {
  freopen("D.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}