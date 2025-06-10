#include <bits/stdc++.h>
// #define int long long

void solve() {
  int n, m, k, a, b;
  std::cin >> n >> m >> k >> a >> b;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  std::priority_queue<std::tuple<int, std::vector<int>, int>, std::vector<std::tuple<int, std::vector<int>, int>>, std::greater<>> q;
  q.push({0, {a}, a});
  std::vector<int> vis(n + 1, k * 12);
  while (!q.empty()) {
    auto [d, vec, u] = q.top(); q.pop();
    if (!vis[u]) continue;
    vis[u]--;
    if (u == b) {
      // std::cerr << d << '\n';
      // for (auto i : vec) {
      //   std::cerr << i << ' ';
      // }
      // std::cerr << '\n';
      if (!--k) {
        std::cout << vec.front();
        for (int i = 1; i < vec.size(); i++) {
          std::cout << "-" << vec[i];
        }
        std::cout << '\n';
        return;
      }
    }
    for (auto [v, w] : g[u]) {
      if (std::find(vec.begin(), vec.end(), v) == vec.end()) {
        vec.push_back(v);
        q.push({d + w, vec, v});
        vec.pop_back();
      }
    }
  }
  std::cout << "No" << '\n';
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