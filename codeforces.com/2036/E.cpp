#include <bits/stdc++.h>
#define int long long

struct Query {
  int x, c;
  bool operator < (const Query &b) const {
    return x < b.x;
  }
};

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      a[i][j] |= a[i - 1][j];
    }
  }
  while (q--) {
    int m;
    std::cin >> m;
    int p = 1;
    bool f = true;
    std::vector<Query> g, l;
    for (int i = 1; i <= m; i++) {
      int x, c;
      char op;
      std::cin >> x >> op >> c;
      if (op == '<') l.push_back({x, c});
      else g.push_back({x, c});
    }
    std::sort(l.begin(), l.end());
    std::sort(g.begin(), g.end());
    for (auto [x, c] : g) {
      int l = p, r = n, nxtp = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid][x] > c) r = mid - 1, nxtp = mid;
        else l = mid + 1;
      }
      if (nxtp == -1) {
        std::cout << -1 << '\n';
        f = false;
        break;
      }
      p = nxtp;
    }
    if (!f) {
      continue;
    }
    for (auto [x, c] : l) {
      if (a[p][x] >= c) {
        std::cout << -1 << '\n';
        f = false;
        break;
      }
    }
    if (f) {
      std::cout << p << '\n';
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};
