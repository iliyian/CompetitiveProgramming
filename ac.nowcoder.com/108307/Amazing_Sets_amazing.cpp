#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> in(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    in[y]++;
  }
  int rt = 0;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      rt = i;
      break;
    }
  }
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::vector<int> dfn(n + 1, -1), low(n + 1), col(n + 1, -1), S;
  int tot = 0, cnt = 0;
  auto tarjan = [&](auto self, int x) -> void {
    dfn[x] = low[x] = tot++;
    S.push_back(x);
    for (auto y : g[x]) {
      if (dfn[y] == -1) {
        self(self, y);
        low[x] = std::min(low[x], low[y]);
      } else if (col[y] == -1) {
        low[x] = std::min(low[x], dfn[y]);
      }
    }
    if (dfn[x] == low[x]) {
      int pre;
      cnt++;
      do {
        pre = S.back();
        col[pre] = cnt;
        S.pop_back();
      } while (pre != x);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (dfn[i] == -1) {
      tarjan(tarjan, i);
    }
  }
  const int N = 1e4;
  std::vector<int> w(cnt + 1), wsum(cnt + 1);
  std::vector<std::vector<int>> adj(cnt + 1);
  for (int i = 1; i <= n; i++) {
    w[col[i]] += a[i];
    for (auto j : g[i]) {
      int x = col[i], y = col[j];
      if (x != y) {
        adj[x].push_back(y);
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    std::sort(adj[i].begin(), adj[i].end());
    adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << col[i] << ' ';
  // }
  // std::cerr << '\n';
  std::vector<std::bitset<N + 1>> f(cnt + 1);
  // std::vector<std::vector<int>> vec(cnt + 1);
  auto dfs = [&](auto &&self, int u) -> void {
    f[u][0] = 1;
    // vec[u].push_back(0);
    wsum[u] = w[u];
    for (int v : adj[u]) {
      self(self, v);
      wsum[u] += wsum[v];
      // std::cerr << v << ": ";
      auto g = f[u];
      // for (int i : vec[v]) {
      for (int i = 0; i <= wsum[v]; i = f[v]._Find_next(i)) {
        // if (f[v][i]) {
          // std::cerr << i << ' ';
          f[u] |= g << i;
        // for (int j : g) {
        //   vec[u].push_back(j + i);
        // }
      }
        // }
        // if (i == 0) break;
      // }
      // std::cerr << '\n';
      
      // vec[u].append_range(vec[v]);
    }
    // vec[u].push_back(wsum[u]);
    // std::ranges::sort(vec[u]);
    // vec[u].erase(std::unique(vec[u].begin(), vec[u].end()), vec[u].end());
    f[u][wsum[u]] = 1;
  };
  // std::cerr << cnt << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << col[i] << " \n"[i == n];
  // }
  dfs(dfs, col[rt]);
  int ans = 0;
  for (int i = 0; i <= wsum[col[rt]]; i = f[col[rt]]._Find_next(i)) {
    // if (f[col[rt]][i]) {
      ans++;
    // }
  }
  // ans = vec[col[rt]].size();
  std::cout << ans << '\n';
  // for (int i = 1; i <= wsum[col[rt]]; i++) {
  // for (int i = 0; i <= wsum[col[rt]]; i++) {
  //   if (f[col[rt]][i]) {
  //     std::cerr << i << ' ';
  //   }
  // }
  // std::cerr << '\n';
}

int32_t main() {
	freopen("d.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
