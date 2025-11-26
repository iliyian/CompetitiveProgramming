#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    l[i] = r[i] = a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  std::vector<std::vector<std::pair<int, int>>> pre(n + 1);
  std::queue<int> q;
  std::vector<int> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (in[i] == 1) {
      q.push(i);
      // vis[i] = 1;
    }
  }
  int ans = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    // if (u == 6) {
    //   for (auto [x, y] : pre[u]) {
    //     // std::cout << x << ' ' << y << '\n';
    //   }
    // }
    // assert(l[u] == r[u]);
    int mxl = 0, mxr = 0;
    for (int i = 1; i < pre[u].size(); i++) {
      auto [x, y] = pre[u][i];
      if (a[u] - y > a[u] - pre[u][mxl].second) {
        mxl = i;
      }
      if (x - a[u] > pre[u][mxr].first - a[u]) {
        mxr = i;
      }
    }
    if (!pre[u].empty()) {
      int ll = a[u], rr = a[u];
      if (a[u] - pre[u][mxl].second >= 0) {
        ans += a[u] - pre[u][mxl].second;
        ll = pre[u][mxl].first;
      }
      if (pre[u][mxr].first - a[u] >= 0) {
        ans += pre[u][mxr].first - a[u];
        rr = pre[u][mxr].second;
      }
      // if (mxl != mxr) {
      //   ans += 
      // }
      l[u] = ll, r[u] = rr;
    }
    // if (u == 4) {
      // std::cout << l[u] << ' ' << r[u] << ' ' << vis[6] << '\n';
    // }
    for (int v : g[u]) {
      if (!vis[v]) {
        --in[v];
        pre[v].push_back({l[u], r[u]});
        if (in[v] == 1) {
          q.push(v);
          // vis[v] = 1;
        }
      }
    }
    // std::cerr << u << ' ' << ans << '\n';
  }
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