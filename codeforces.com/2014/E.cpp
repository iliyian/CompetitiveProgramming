#include <bits/stdc++.h>
#include <queue>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

struct Node {
  int u, d;
  bool horsed;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void solve() {
  int n, m, h;
  std::cin >> n >> m >> h;
  std::priority_queue<Node> q;
  std::vector<int> has(n + 1);
  for (int i = 1; i <= h; i++) {
    int x;
    std::cin >> x;
    has[x] = true;
  }
  std::vector<std::vector<std::pair<int, int>>> g(n * 2 + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    g[x + n].push_back({y + n, w / 2});
    g[y + n].push_back({x + n, w / 2});
  }
  for (int i = 1; i <= n; i++) {
    if (has[i]) {
      g[i].push_back({i + n, 0});
    }
  }
  std::vector<int> dis(n * 2 + 1, inf), vis(n * 2 + 1);
  auto dijkstra = [&](int s) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    std::fill(dis.begin(), dis.end(), inf);
    std::fill(vis.begin(), vis.end(), 0);
    q.push({dis[s] = 0, s});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          q.push({dis[v], v});
        }
      }
    }
  };
  std::vector<int> dis1(n * 2 + 1);
  dijkstra(1);
  std::copy(dis.begin(), dis.end(), dis1.begin());
  dijkstra(n);

  int ans = inf;
  for (int i = 1; i <= n; i++) {
    int cur = std::max(std::min(dis1[i], dis1[i + n]), std::min(dis[i], dis[i + n]));
    ans = std::min(ans, cur);
    // std::cout << std::min(dis1[i], dis1[i + n]) << ' ' << std::min(dis[i], dis[i + n]) << '\n';
    // std::cout << dis1[i] << ' ' << dis1[i + n] << ' ' << dis[i] << ' ' << dis[i + n] << '\n';
  }
  std::cout << (ans == inf ? -1 : ans) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E.in", "r", stdin);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}