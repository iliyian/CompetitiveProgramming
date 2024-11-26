#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5, MAXD = 1e6;

int n, k, sum, rt = 0;

std::vector<std::pair<int, int>> g[N + 1];
std::vector<int> siz(N + 1), maxx(N + 1), vis(N + 1), dis(N + 1);
std::vector<int> mn(MAXD + 1, INT_MAX);

void getrt(int u, int p) {
  siz[u] = 1;
  maxx[u] = 0;
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      getrt(v, u);
      siz[u] += siz[v];
      maxx[u] = std::max(maxx[u], siz[v]);
    }
  }
  maxx[u] = std::max(maxx[u], sum - siz[u]);
  if (maxx[u] < maxx[rt]) {
    rt = u;
  }
}

std::vector<std::pair<int, int>> vec, cur;

void getdis(int u, int p, int len) {
  if (dis[u] > k) return;
  cur.push_back({dis[u], len});
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      dis[v] = dis[u] + w;
      getdis(v, u, len + 1);
    }
  }
}

int ans = INT_MAX;

void work(int u, int p) {
  vis[u] = 1;
  mn[0] = 0;
  vec.push_back({0, 0});
  for (auto [v, w] : g[u]) {
    if (!vis[v] && v != p) {
      dis[v] = w;
      getdis(v, u, 1);
      for (auto [d, len] : cur) {
        ans = std::min(ans, mn[k - d] + len);
      }
      while (!cur.empty()) {
        mn[cur.back().first] = std::min(mn[cur.back().first], cur.back().second);
        vec.push_back(cur.back());
        cur.pop_back();
      }
    }
  }
  while (!vec.empty()) {
    mn[vec.back().first] = INT_MAX;
    vec.pop_back();
  }
  for (auto [v, w] : g[u]) {
    if (!vis[v] && v != p) {
      rt = 0;
      sum = siz[v];
      getrt(v, u);
      work(rt, u);
    }
  }
}

void solve() {
  std::cin >> n >> k;
  sum = n;
  maxx[0] = INT_MAX;
  for (int i = 2; i <= n - 1; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    x++, y++;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  getrt(1, 0);
  work(rt, 0);
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}