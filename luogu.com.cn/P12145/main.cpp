#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> isring(n + 1), vis(n + 1), id(n + 1), pa(n + 1), rt(n + 1);
  int tot = 0;
  bool f = false;
  auto dfs = [&](auto self, int u, int p) -> void {
    if (f) return;
    for (int v : g[u]) {
      if (v != p) {
        if (f) return;
        if (vis[v]) {
          f = true;
          isring[v] = 1;
          id[v] = ++tot;
          while (u != v) {
            isring[u] = 1;
            id[u] = ++tot;
            u = pa[u];
          }
          return;
        }
        pa[v] = u;
        vis[v] = 1;
        self(self, v, u);
      }
    }
  };
  vis[1] = 1;
  dfs(dfs, 1, 0);
  std::vector<int> w(n + 1);
  auto dfs2 = [&](auto self, int u, int p) -> void {
    w[u] = a[u];
    for (int v : g[u]) {
      if (v == p || isring[v]) continue;
      self(self, v, u);
      w[u] = std::max(w[u], w[v] + a[u]);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (isring[i]) {
      rt[id[i]] = i;
      dfs2(dfs2, i, 0);
    }
  }
  std::vector<int> val(tot * 2 + 1), s(tot * 2 + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (isring[i]) {
      cur++;
      val[cur] = val[cur + tot] = w[i];
      s[cur] = s[cur + tot] = a[i];
      // std::cerr << i << ' ' << cur << ' ' << val[cur] << ' ' << s[cur] << '\n';
    }
  }
  for (int i = 1; i <= tot * 2; i++) {
    s[i] += s[i - 1];
  }
  int ans = 0;
  std::deque<int> q;
  for (int i = 1; i <= tot * 2; i++) {
    while (!q.empty() && q.front() <= i - tot) q.pop_front();
    if (i >= tot + 1) {
      ans = std::max(ans, val[q.front()] - s[q.front()] + val[i] + s[i - 1]);
    }
    while (!q.empty() && val[q.back()] - s[q.back()] < val[i] - s[i]) q.pop_back();
    q.push_back(i);
    // std::cerr << i << ' ' << ans << '\n';
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