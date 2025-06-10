// date: 2025-04-29 21:41:00
// tag: 比较套路的数位dp？？

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string l, r;
  std::cin >> l >> r;
  if (l.size() < r.size()) {
    for (int i = 0; i < l.size(); i++) {
      std::cout << 9;
    }
    std::cout << '\n';
    return;
  }
  bool f = false;
  std::string cur;
  auto dfs = [&](auto self, int u, bool f, bool g, int mx) -> bool {
    if (u == l.size()) {
      return true;
    }
    for (int i = (f ? 0 : l[u] - '0');
         i <= (g ? 9 : r[u] - '0'); i++) {
      bool h = true;
      for (auto j : cur) {
        if (std::abs(i + '0' - j) > mx) {
          h = false;
          break;
        }
      }
      if (!h) continue;
      cur.push_back(i + '0');
      if (self(self, u + 1, f | (i != l[u] - '0'), g | (i != r[u] - '0'), mx)) {
        return true;
      }
      cur.pop_back();
    }
    return false;
  };
  for (int mx = 0; mx < 10; mx++) {
    if (dfs(dfs, 0, false, false, mx)) {
      std::cout << cur << '\n';
      return;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}