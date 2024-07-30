// date: 2024-07-30 14:04:52
// tag: 枚举

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::vector<std::pair<int, int>>> dis(n + 1, std::vector<std::pair<int, int>>(n + 1));
  std::vector<std::vector<std::pair<int, int>>> rdis(n + 1, std::vector<std::pair<int, int>>(n + 1));
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = {INT_MIN, j};
    }
  }
  std::queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    q.push({i, 0});
    while (!q.empty()) {
      auto [u, d] = q.front(); q.pop();
      if (dis[i][u].first != INT_MIN) continue;
      dis[i][u].first = d;
      for (int v : g[u]) {
        q.push({v, d + 1});
      }
    }
    std::sort(dis[i].begin() + 1, dis[i].end(), std::greater());
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int y = dis[i][j].second, d = dis[i][j].first;
      rdis[y][i].first = d;
      rdis[y][i].second = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::sort(rdis[i].begin() + 1, rdis[i].end(), std::greater());
  }
  int ansa = 0, ansb = 0, ansc = 0, ansd = 0, ansdis = 0;
  for (int b = 1; b <= n; b++) {
    for (int c = 1; c <= n; c++) {
      auto [dbc, C] = dis[b][c];
      if (C == b) continue;
      for (int i = 1; i <= 3; i++) {
        auto [dab, a] = rdis[b][i];
        if (a == b || a == C) continue;
        for (int j = 1; j <= 3; j++) {
          auto [dcd, d] = dis[C][j];
          if (d == a || d == b || d == C) continue;
          if (dab + dbc + dcd > ansdis) {
            ansdis = dab + dbc + dcd;
            ansa = a, ansb = b, ansc = C, ansd = d;
          }
        }
      }
    }
  }
  std::cout << ansa << ' ' << ansb << ' ' << ansc << ' ' << ansd << '\n';

  return 0;
}