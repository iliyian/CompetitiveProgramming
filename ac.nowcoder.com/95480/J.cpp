#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n + 1), c(n + 1), a(n + 1);
  std::vector<int> vec = {INT_MIN};
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i];
    vec.push_back(v[i]);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  std::sort(vec.begin(), vec.end());
  int len = vec.size() - 1;
  std::vector<int> d(len << 2, INT_MAX);
  auto modify = [&](auto self, int x, int s, int t, int p, int c) -> void {
    if (x > t || x < s) return;
    if (s == t) {
      d[p] = std::min(d[p], c);
      return;
    }
    self(self, x, s, mid, lc, c);
    self(self, x, mid + 1, t, rc, c);
    d[p] = std::min(d[lc], d[rc]);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return INT_MAX;
    if (l <= s && t <= r) {  
      return d[p];
    }
    return std::min(self(self, l, r, s, mid, lc), self(self, l, r, mid + 1, t, rc));
  };
  for (int i = n; i >= 1; i--) {
    modify(modify, id(v[i]), 1, len, 1, c[i]);
    ans[i] = query(query, id(a[i]), len, 1, len, 1);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (ans[i] == INT_MAX ? -1 : ans[i]) << " \n"[i == n];
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}