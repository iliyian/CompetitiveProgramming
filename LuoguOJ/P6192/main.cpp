// date: 2024-07-28 10:05:26
// tag: 斯坦纳树

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(1 << k, inf));
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<int> key(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> key[i];
    f[key[i]][1 << (i - 1)] = 0;
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::vector<int> vis(n + 1);
  auto dijkstra = [&](int S) {
    std::fill(vis.begin(), vis.end(), 0);
    while (!q.empty()) {
      int x = q.top().second; q.pop();
      if (vis[x]) continue;
      vis[x] = true;
      for (auto [y, w] : g[x]) {
        if (f[y][S] > f[x][S] + w) {
          f[y][S] = f[x][S] + w;
          q.push({f[y][S], y});
        }
      }
    }
  };
  for (int S = 1; S < (1 << k); S++) {
    for (int i = 1; i <= n; i++) {
      for (int sub = S & (S - 1); sub; sub = S & (sub - 1)) {
        f[i][S] = std::min(f[i][S], f[i][sub] + f[i][S ^ sub]);
      }
      if (f[i][S] != inf) {
        q.push({f[i][S], i});
      }
    }
    dijkstra(S);
  }
  std::cout << f[key[1]][(1 << k) - 1] << '\n';

  return 0;
}