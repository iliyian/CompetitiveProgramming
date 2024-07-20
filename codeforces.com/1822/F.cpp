// date: 2024-07-17 14:54:19
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k, c;
  std::cin >> n >> k >> c;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  
  std::vector<int> dep(n + 1), maxlen(n + 1);
  auto dfs1 = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        maxlen[u] = std::max(maxlen[u], maxlen[v] + 1);
      }
    }
  };
  dfs1(dfs1, 1, 0);

  int ans = -1;
  auto dfs2 = [&](auto self, int u, int p, int mxlen) -> void {
    std::multiset<int> s;
    s.insert(mxlen);

    for (int v : g[u]) {
      if (v != p) {
        s.insert(maxlen[v] + 1);
      }
    }

    ans = std::max(ans, (*s.rbegin()) * k - (dep[u] - 1) * c);

    for (int v : g[u]) {
      if (v != p) {
        s.erase(s.find(maxlen[v] + 1));
        self(self, v, u, *s.rbegin() + 1);
        s.insert(maxlen[v] + 1);
      }
    }
  };
  dfs2(dfs2, 1, 0, 0);

  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}