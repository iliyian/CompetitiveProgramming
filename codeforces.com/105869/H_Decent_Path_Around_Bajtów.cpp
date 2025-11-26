#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::vector<std::vector<int>> g(n), h(n), e(n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> s >> y;
    x--, y--;
    if (s == "->") {
      g[x].push_back(y);
      h[y].push_back(x);
    } else {
      e[x].push_back(y);
      e[y].push_back(x);
    }
  }
  std::vector<std::vector<int>> pre(n), suf(n), all(n);
  for (int i = 0; i < n; i++) {
    for (int v : e[i]) {
      all[i].push_back(v);
    }
    for (int v : g[i]) {
      all[i].push_back(v);
    }
  }
  for (int i = 0; i < n; i++) {
    pre[i].assign(all[i].size() + 1, 0);
    suf[i].assign(all[i].size() + 1, 0);
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