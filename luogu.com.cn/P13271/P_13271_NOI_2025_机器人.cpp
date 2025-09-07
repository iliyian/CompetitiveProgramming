#include <bits/stdc++.h>
#define int long long

void solve() {
  int _;
  std::cin >> _;
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<int> V(k + 1), W(k + 1);
  for (int i = 1; i <= k - 1; i++) {
    std::cin >> V[i];
    V[i] += V[i - 1];
  }
  for (int i = 2; i <= k; i++) {
    std::cin >> W[i];
    W[i] += W[i - 1];
  }
  std::vector<std::vector<int>> dis(n + 1);
  std::vector<std::vector<int>> from(n + 1);
  for (int i = 1; i <= n; i++) {
    int d;
    std::cin >> d;
    for (int j = 1; j <= d; j++) {
      int y, z;
      std::cin >> y >> z;
      g[i].push_back({y, z});
      from[y].push_back(j);
    }
  }
  from[1].push_back(1);
  for (int i = 1; i <= n; i++) {
    std::ranges::sort(from[i]);
    dis[i].assign(from[i].size(), LLONG_MAX / 3);
  }
  auto get = [&](int y, int j) {
    return std::ranges::lower_bound(from[y], j) - from[y].begin();
  };
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  q.push({dis[1][0] = 0, 1, 0});
  while (!q.empty()) {
    auto [d, u, idx] = q.top(); q.pop();
    if (dis[u][idx] != d) continue;
    int p = from[u][idx];
    for (int i = 0; i < g[u].size(); i++) {
      auto [v, w] = g[u][i];
      if (v == 1) continue;
      int jdx = get(v, i + 1);
      int c = 0;
      if (i + 1 > p && i + 1 <= k) {
        c = V[i] - V[p - 1];
      } else if (i + 1 < p) {
        c = W[p] - W[i + 1];
      }
      if (dis[v][jdx] > dis[u][idx] + w + c) {
        dis[v][jdx] = dis[u][idx] + w + c;
        q.push({dis[v][jdx], v, jdx});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int ans = LLONG_MAX / 3;
    for (int j : dis[i]) {
      ans = std::min(ans, j);
    }
    std::cout << (ans == LLONG_MAX / 3 ? -1 : ans) << ' ';
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