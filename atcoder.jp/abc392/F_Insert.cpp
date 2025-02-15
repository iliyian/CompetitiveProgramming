// date: 2025-02-09 14:37:28
// tag: 正难则反的附加版本，顺难则逆

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 5e5;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  std::vector<int> d(N << 2);
  auto add = [&](auto self, int x, int s, int t, int p, int c) -> void {
    if (x > t || x < s) return;
    if (s == t) {
      d[p] += c;
      return;
    }
    self(self, x, s, mid, lc, c);
    self(self, x, mid + 1, t, rc, c);
    d[p] = d[lc] + d[rc];
  };
  auto query = [&](auto self, int s, int t, int p, int c) -> int {
    if (s == t) return s;
    if (d[lc] >= c) return self(self, s, mid, lc, c);
    return self(self, mid + 1, t, rc, c - d[lc]);
  };
  for (int i = 1; i <= n; i++) {
    add(add, i, 1, n, 1, 1);
  }
  std::vector<int> ans(n + 1);
  for (int i = n; i >= 1; i--) {
    int x = query(query, 1, n, 1, p[i]);
    ans[x] = i;
    add(add, x, 1, n, 1, -1);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}