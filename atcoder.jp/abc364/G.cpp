// date: 2024-07-28 10:43:47
// tag: 斯坦纳树
// 顺便把s放在第一维确实能跨一点，在atcoder上这题快了14%

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::vector<int>> f(1 << (k - 1), std::vector<int>(n + 1, inf));

  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  for (int i = 1; i <= k - 1; i++) {
    f[1 << (i - 1)][i] = 0;
  }

  std::vector<int> vis(n + 1);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  auto dijkstra = [&](int s) {
    std::fill(vis.begin(), vis.end(), 0);
    while (!q.empty()) {
      int x = q.top().second; q.pop();
      if (vis[x]) continue;
      vis[x] = true;
      for (auto [y, w] : g[x]) {
        if (f[s][y] > f[s][x] + w) {
          f[s][y] = f[s][x] + w;
          q.push({f[s][y], y});
        }
      }
    }
  };
  for (int s = 1; s < (1 << (k - 1)); s++) {
    for (int i = 1; i <= n; i++) {
      for (int sub = s & (s - 1); sub; sub = s & (sub - 1)) {
        if (sub < (s ^ sub)) {
          break;
        }
        f[s][i] = std::min(f[s][i], f[sub][i] + f[s ^ sub][i]);
      }
      if (f[s][i] != inf) {
        q.push({f[s][i], i});
      }
    }
    dijkstra(s);
  }

  for (int i = k; i <= n; i++) {
    std::cout << f[(1 << (k - 1)) - 1][i] << '\n';
  }

  return 0;
}