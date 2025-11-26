#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> v(k + 1);
  std::vector<int> vt(k + 1);
  for (int i = 1; i <= k; i++) {
    int sc;
    std::cin >> vt[i] >> sc;
    for (int j = 1; j <= sc; j++) {
      int x;
      std::cin >> x;
      v[i].push_back(x);
    }
  }
  std::vector<int> p(k + 1);
  std::ranges::iota(p, 0);
  std::sort(p.begin() + 1, p.end(), [&](auto x, auto y) {
    return vt[x] < vt[y];
  });
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<>> q;
  std::vector<int> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      q.push({0, i});
    }
  }
  int pt = 1;
  std::vector<int> ans(n + 1, -1);
  auto addpt = [&]() {
    for (int x : v[p[pt]]) {
      if (!vis[x]) {
        q.push({vt[p[pt]], x});
        a[x] = 0;
      }
    }
    pt++;
  };
  auto work = [&]() {
    while (!q.empty()) {
      auto [t, u] = q.top(); q.pop();
      // std::cerr << t << ' ' << u << '\n';
      bool f = false;
      while (pt <= k && vt[p[pt]] <= t) {
        addpt();
        f = true;
      }
      if (f) {
        q.push({t, u});
        continue;
      }
      a[u]--;
      if (a[u] > 0) continue;
      if (vis[u]) continue;
      ans[u] = t;
      vis[u] = 1;
      for (auto [v, w] : g[u]) {
        if (!vis[v]) {
          q.push({t + w, v});
        }
      }
    }
  };
  work();
  while (pt <= k) {
    addpt();
    work();
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