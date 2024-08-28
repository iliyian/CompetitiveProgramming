// date: 2024-08-27 13:31:04
// tag: 矩阵匹配转费用流

#include <bits/stdc++.h>
#include <queue>
#define int long long
// using namespace std;

constexpr int N = 102;

struct Edge {
  int v, w, cap, id;
};
int n, m, s, t, minc;

std::vector<Edge> g[N + 1];
std::vector<int> h(N + 1), dis(N + 1);
std::bitset<N + 1> vis;

void add(int u, int v, int w, int cap) {
  g[u].push_back({v, w, cap, (int)g[v].size()});
  g[v].push_back({u, -w, 0, (int)g[u].size() - 1});
}

void spfa() {
  std::queue<int> q;
  std::fill(h.begin(), h.end(), INT_MAX);
  vis[s] = true;
  h[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (auto &[v, w, cap, id] : g[u]) {
      if (cap && h[v] > h[u] + w) {
        h[v] = h[u] + w;
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
}

std::vector<std::pair<int, int>> p(N + 1);

bool dijkstra() {
  std::fill(dis.begin(), dis.end(), INT_MAX);
  vis.reset();
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({dis[s] = 0, s});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
      auto [v, w, cap, id] = g[u][i];
      int nw = w + h[u] - h[v];
      if (cap && dis[v] > dis[u] + nw) {
        dis[v] = dis[u] + nw;
        p[v] = {u, i};
        q.push({dis[v], v});
      }
    }
  }
  return dis[t] != INT_MAX;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::cin >> n >> m;
  s = 0, t = n + m + 1;
  int maxf = 0, minc = 0, suma = 0, sumb = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      std::cin >> x;
      add(i, n + j, x ? -1 : 1, 1);
      minc += x;
    }
  }
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    add(s, i, 0, x);
    suma += x;
  }
  for (int j = 1; j <= m; j++) {
    int x;
    std::cin >> x;
    add(n + j, t, 0, x);
    sumb += x;
  }
  if (suma != sumb) {
    std::cout << -1 << '\n';
    return 0;
  }
  spfa();
  while (dijkstra()) {
    int minf = INT_MAX;
    for (int i = s; i <= t; i++) {
      h[i] += dis[i];
    }
    for (int i = t; i != s; i = p[i].first) {
      minf = std::min(minf, g[p[i].first][p[i].second].cap);
    }
    for (int i = t; i != s; i = p[i].first) {
      auto &e = g[p[i].first][p[i].second];
      e.cap -= minf;
      g[i][e.id].cap += minf;
    }
    maxf += minf;
    minc += minf * h[t];
  }
  std::cout << (maxf == suma ? minc : -1) << '\n';

  return 0;
}