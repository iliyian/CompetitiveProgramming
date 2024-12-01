#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

std::vector<std::vector<int>> g;
int siz[N + 1], vis[N + 1], maxx[N + 1], pos[N + 1], pre[N + 1], a[N + 1], cnt[N + 1];
int cur[N + 1], tot[N + 1];

int sum, rt, ans, n;

void getrt(int u, int p) {
  siz[u] = 1;
  for (auto v : g[u]) {
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
};

void calc(int u, int p) {
  pre[u] = pos[a[u]], pos[a[u]] = u;
  if (!pre[u]) {
    if (a[u] == a[rt]) ans++;
    else {
      ans += tot[a[u]];
      cur[a[u]]++;
    }
  }
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      calc(v, u);
    }
  }
  pos[a[u]] = pre[u];
};

void update(int u, int p) {
  tot[a[u]] += cur[a[u]], cur[a[u]] = 0;
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      update(v, u);
    }
  }
}

void clear(int u, int p) {
  tot[a[u]] = cur[a[u]] = pos[a[u]] = pre[a[u]] = 0;
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      clear(v, u);
    }
  }
}

void work(int u, int p) {
  vis[u] = 1;
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      calc(v, u);
      // s.clear();
      update(v, u);
    }
  }
  clear(u, p);
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      sum = siz[v];
      rt = 0;
      getrt(v, u);
      work(rt, u);
    }
  }
}

void solve() {
  std::cin >> n;
  g.assign(n + 1, {});
  for (int i = 1; i <= n; i++) {
    vis[i] = siz[i] = cnt[i] = maxx[i] = pos[i] = pre[i] = 0;
  }
  // vis.assign(n + 1, 0);
  // siz.assign(n + 1, 0);
  // cnt.assign(n + 1, 0);
  // maxx.assign(n + 1, 0);
  // pos.assign(n + 1, 0);
  // pre.assign(n + 1, 0);
  // a.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  sum = n, rt = 0, ans = 0;
  maxx[0] = INT_MAX;

  getrt(1, 0);
  work(rt, 0);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}