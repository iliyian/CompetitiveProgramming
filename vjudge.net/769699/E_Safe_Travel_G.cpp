#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::array<int, 3>> e;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    e.push_back({x, y, w});
  }
  std::vector<int> dis(n + 1, LLONG_MAX / 3), pre(n + 1), dep(n + 1);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({dis[1] = 0, 1});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (auto [v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        pre[v] = u;
        dep[v] = dep[u] + 1;
        q.push({dis[v] = dis[u] + w, v});
      }
    }
  }
  std::ranges::sort(e, [&](auto x, auto y) {
    return dis[x[0]] + dis[x[1]] + x[2] < dis[y[0]] + dis[y[1]] + y[2];
  });
  std::vector<int> pa(n + 1);
  std::ranges::iota(pa, 0);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  std::vector<int> ans(n + 1, -1);
  for (auto [x, y, w] : e) {
    if (pre[x] == y || pre[y] == x) {
      continue;
    }
    int val = dis[x] + dis[y] + w;
    x = find(x), y = find(y);
    while (x != y) {
      if (dep[x] < dep[y]) std::swap(x, y);
      ans[x] = val - dis[x];
      pa[x] = pre[x];
      x = find(x);
    }
  }
  for (int i = 2; i <= n; i++) {
    std::cout << ans[i] << '\n';
  }
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
