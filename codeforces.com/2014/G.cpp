#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::stack<std::pair<int, int>> s;
  int ans = 0, prv = 0;
  for (int i = 1; i <= n; i++) {
    int d, a;
    std::cin >> d >> a;
    while (!s.empty()) {
      int has = std::min()
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}