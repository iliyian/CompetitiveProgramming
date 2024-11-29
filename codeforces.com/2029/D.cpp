// date: 2024-11-28 23:18:24
// tag: 构造，图论

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::set<int>> g(n + 1);
  int cnt = 0;
  std::vector<std::pair<int, int>> edges(m + 1);

  auto op = [&](int x, int y, int z) {
    if (g[x].contains(y)) {
      g[x].erase(y);
      g[y].erase(x);
    } else {
      g[x].insert(y);
      g[y].insert(x);
    }
    if (g[y].contains(z)) {
      g[y].erase(z);
      g[z].erase(y);
    } else {
      g[y].insert(z);
      g[z].insert(y);
    }
    if (g[x].contains(z)) {
      g[x].erase(z);
      g[z].erase(x);
    } else {
      g[x].insert(z);
      g[z].insert(x);
    }
  };

  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);
    edges[i] = {x, y};
    g[x].insert(y);
    g[y].insert(x);
  }
  if (m == 0) {
    std::cout << 0 << '\n';
    return;
  }
  std::vector<std::array<int, 3>> ans;
  std::set<int> bam, sol;
  for (int i = 1; i <= n; i++) {
    while (g[i].size() > 1) {
      int x = *g[i].begin(), y = *g[i].rbegin();
      op(i, x, y);
      ans.push_back({i, x, y});
    }
    if (g[i].empty()) {
      sol.insert(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1 && g[*g[i].begin()].size() == 1 && !bam.count(*g[i].begin())) {
      bam.insert(i);
    }
  }
  if (bam.empty()) {
    std::cout << ans.size() << '\n';
    for (auto [x, y, z] : ans) {
      std::cout << x << ' ' << y << ' ' << z << '\n';
    }
    return;
  }
  int heart = *bam.begin();
  bam.erase(bam.begin());
  for (int i : bam) {
    ans.push_back({heart, i, *g[i].begin()});
  }
  int sec = *g[heart].begin();
  while (!sol.empty()) {
    int u = *sol.begin(); sol.erase(u);
    ans.push_back({heart, sec, u});
    sec = u;
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y, z] : ans) {
    std::cout << x << ' ' << y << ' ' << z << '\n';
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