// date: 2024-11-18 21:38:24
// tag: 点分治，模意义下的路径长度计数

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    w %= 3;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  std::vector<int> vis(n + 1), dis(n + 1), siz(n + 1), cur(3);
  int rt = 0;
  auto calcdis = [&](auto self, int u, int p) -> void {
    cur[dis[u] % 3]++;
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        dis[v] = dis[u] + w;
        dis[v] %= 3;
        self(self, v, u);
      }
    }
  };

  int sum = n, ans = 0;
  std::vector<int> maxx(n + 1);
  auto getrt = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    maxx[u] = 0;
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], sum - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };

  std::vector<int> cnt(3), oked;
  int tot = 0;
  auto work = [&](auto self, int u, int p) -> void {
    tot++;
    vis[u] = true;
    cnt.assign(3, 0);
    cnt[0] = 1;
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        dis[v] = w;
        calcdis(calcdis, v, u);
        for (int i = 0; i < 3; i++) {
          if (cur[i]) {
            ans += cur[i] * cnt[(3 - i) % 3];
          }
        }
        for (int i = 0; i < 3; i++) {
          cnt[i] += cur[i];
          cur[i] = 0;
        }
      }
    }
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        rt = 0;
        sum = siz[v];
        getrt(getrt, v, u);
        self(self, rt, 0);
      }
    }
  };

  rt = 0;
  maxx[0] = INT_MAX;
  getrt(getrt, 1, 0);
  work(work, rt, 0);
  ans = ans * 2 + n;

  int gcd = std::gcd(ans, n * n);
  std::cout << ans / gcd << '/' << n * n / gcd << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}