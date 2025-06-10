#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k, p;
  std::cin >> n >> m >> k >> p;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<int> pos(k * 2);
  for (int i = 0; i < k; i++) {
    std::cin >> pos[i << 1] >> pos[i << 1 | 1];
  }
  std::vector<std::vector<int>> dis(k * 2, std::vector<int>(n + 1, LLONG_MAX / 3));
  auto dijkstra = [&](int s) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.push({dis[s][pos[s]] = 0, pos[s]});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (dis[s][u] != d) continue;
      for (auto &[v, w] : g[u]) {
        if (dis[s][v] > dis[s][u] + w) {
          q.push({dis[s][v] = dis[s][u] + w, v});
        }
      }
    }
  };
  for (int i = 0; i < k * 2; i++) {
    dijkstra(i);
  }

  std::vector<int> disp(n + 1, LLONG_MAX / 3);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({disp[p] = 0, p});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (disp[u] != d) continue;
    for (auto &[v, w] : g[u]) {
      if (disp[v] > disp[u] + w) {
        q.push({disp[v] = disp[u] + w, v});
      }
    }
  }


  std::vector<int> p3(k + 1);
  p3[0] = 1;
  for (int i = 1; i <= k; i++) {
    p3[i] = p3[i - 1] * 3;
  }
  int mxS = p3[k];
  std::vector<std::vector<int>> f(2 * k, std::vector<int>(mxS, LLONG_MAX / 3));
  // 当前在第 i 个点，状态为 mxS

  auto set = [&](int S, int pos, int v) {
    int r = S % p3[pos];
    S /= p3[pos];
    S = S - (S % 3) + v;
    S = S * p3[pos] + r;
    return S;
  };
  auto get = [&](int S, int pos) {
    return S / p3[pos] % 3;
  };
  for (int i = 0; i < k * 2; i += 2) {
    f[i][set(0, i / 2, 1)] = disp[pos[i]];
  }

  for (int S = 1; S < mxS; S++) {
    for (int i = 0; i < k * 2; i += 2) { // 起点到起点或终点
      if (get(S, i / 2) == 1) {
        for (int j = 1; j < k * 2; j += 2) { // 到终点
          if (get(S, j / 2) == 1) {// 这个外卖拿了
            f[j][set(S, j / 2, 2)] = std::min(f[j][set(S, j / 2, 2)], f[i][S] + dis[i][pos[j]]);
          }
        }
        for (int j = 0; j < k * 2; j += 2) { // 到起点
          if (get(S, j / 2) == 0) {// 这个外卖没拿
            f[j][set(S, j / 2, 1)] = std::min(f[j][set(S, j / 2, 1)], f[i][S] + dis[i][pos[j]]);
          }
        }
      }
    }
    for (int i = 1; i < k * 2; i += 2) { // 终点到其他起点和终点
      if (get(S, i / 2) == 2) {
        for (int j = 0; j < k * 2; j += 2) { // 到起点
          if (get(S, j / 2) == 0) {// 这个外卖没拿
            f[j][set(S, j / 2, 1)] = std::min(f[j][set(S, j / 2, 1)], f[i][S] + dis[i][pos[j]]);
          }
        }
        for (int j = 1; j < k * 2; j += 2) { // 到终点
          if (get(S, j / 2) == 1) {// 这个外卖拿了
            f[j][set(S, j / 2, 2)] = std::min(f[j][set(S, j / 2, 2)], f[i][S] + dis[i][pos[j]]);
          }
        }
      }
    }
  }
  int ans = LLONG_MAX / 3;
  for (int i = 1; i < k * 2; i += 2) {
    ans = std::min(ans, f[i][mxS - 1]);
  }
  std::cout << ans << '\n';
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