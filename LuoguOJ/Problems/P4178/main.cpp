// date: 2024-11-21 14:17:58
// tag: 基于区间和单点加的点分治
// 疑似直接用树状数组就可以了。。。。

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 4e4, MAXD = 2e4 + 10;
std::vector<std::pair<int, int>> g[N + 1];

int dis[N + 1], siz[N + 1], maxx[N + 1], vis[N + 1];
int n, m, sum, rt = 0, k;

int d[MAXD << 2];

void add(int x, int s, int t, int p, int c) {
  if (x < s || x > t) return;
  if (s == t) {
    d[p] += c;
    return;
  }
  add(x, s, mid, lc, c);
  add(x, mid + 1, t, rc, c);
  d[p] = d[lc] + d[rc];
}

void add(int x, int c) {
  add(x + 1, 1, MAXD, 1, c);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[p];
  return query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc);
}

int query(int l, int r) {
  return query(l + 1, r + 1, 1, MAXD, 1);
}

void getrt(int u, int p) {
  siz[u] = 1;
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

std::vector<int> vec, cur;

int ans = 0;

void calcdis(int u, int p) {
  if (dis[u] > k) return;
  cur.push_back(dis[u]);
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      dis[v] = dis[u] + w;
      calcdis(v, u);
    }
  }
}

void work(int u, int p) {
  vis[u] = true;
  vec.push_back(0);
  add(0, 1);
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      dis[v] = w;
      calcdis(v, u);
      for (int i : cur) {
        ans += query(0, k - i);
      }
      while (!cur.empty()) {
        add(cur.back(), 1);
        vec.push_back(cur.back()), cur.pop_back();
      }
    }
  }
  while (!vec.empty()) {
    add(vec.back(), -1);
    vec.pop_back();
  }
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      rt = 0;
      sum = siz[v];
      getrt(v, u);
      work(v, u);
    }
  }
}

void solve() {
  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::cin >> k;
  maxx[0] = INT_MAX;
  rt = 0;
  sum = n;
  getrt(1, 0);
  work(rt, 0);
  std::cout << ans << '\n';
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