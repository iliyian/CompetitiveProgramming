// date: 2025-05-24 16:24:20
// tag: 感觉是一段时间以来写的最长的代码了。真想不到点分治还能处理这种比较复杂的距离问题。有点类似于多源最短路。点分治真神奇。
// 点分治可以处理一切路径上的半群信息？至少距离还是绰绰有余的。

#include <bits/stdc++.h>
// #define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> a(m + 1), is(n + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  std::vector<int> siz(n + 1), maxx(n + 1), vis(n + 1);
  maxx[0] = INT_MAX;
  int rt = 0, tot = n;
  auto getrt = [&](auto self, int u, int p) -> void {
    siz[u] = 1, maxx[u] = 0;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(tot - siz[u], maxx[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };
  auto check = [&](int mid) {
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      is[a[i]] = 1;
    }
    std::vector<int> cur, prv(n + 1), cnt(n + 1), prvall;
    int sum = 0, nowsum = 0;
    auto dfs = [&](auto self, int u, int p, int d, int nowsum) -> void {
      if (d > mid) return;
      if (is[u]) {
        cur.push_back(mid - d);
      }
      cnt[u] += nowsum;
      for (int v : g[u]) {
        if (!vis[v] && v != p) {
          self(self, v, u, d + 1, nowsum - prv[d]);
        }
      }
    };
    // 根节点为花，则根节点为一端的路径
    auto dfs2 = [&](auto self, int u, int p, int d, bool f) -> void {
      if (d > mid) return;
      if (f) {
        cnt[u]++;
      }
      for (int v : g[u]) {
        if (v != p && !vis[v]) {
          self(self, v, u, d + 1, f);
        }
      }
    };
    auto dfz = [&](auto self, int u, int p) -> void {
      vis[u] = 1, sum = nowsum = 0;
      for (int v : g[u]) {
        if (!vis[v] && v != p) {
          dfs(dfs, v, u, 1, sum - prv[0]);
          for (int i = 0; i < cur.size(); i++) {
            prv[cur[i]]++;
            sum++;
          } 
          while (!cur.empty()) {
            prvall.push_back(cur.back()); cur.pop_back();
          }
        }
      }
      while (!prvall.empty()) {
        prv[prvall.back()] = 0, prvall.pop_back();
      }
      sum = nowsum = 0;
      for (int v : g[u] | std::views::reverse) {
        if (!vis[v] && v != p) {
          dfs(dfs, v, u, 1, sum - prv[0]);
          for (int i = 0; i < cur.size(); i++) {
            prv[cur[i]]++;
            sum++;
          } 
          while (!cur.empty()) {
            prvall.push_back(cur.back()); cur.pop_back();
          }
        }
      }
      while (!prvall.empty()) {
        prv[prvall.back()] = 0, prvall.pop_back();
      }
      cnt[u] += sum;
      dfs2(dfs2, u, 0, 0, is[u]);
      for (int v : g[u]) {
        if (v != p && !vis[v]) {
          tot = siz[v], rt = 0;
          getrt(getrt, v, 0);
          self(self, rt, 0);
        }
      }
    };
    rt = 0, tot = n;
    getrt(getrt, 1, 0);
    dfz(dfz, rt, 0);
    for (int i = 1; i <= n; i++) {
      if (cnt[i] <= k) {
        return true;
      }
    }
    return false;
  };
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans + 1 << '\n';
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