#include <bits/stdc++.h>
// #define int long long

std::vector<int> in;
std::vector<std::vector<int>> gg, g;

void dfs2(int u, int p) {
    // _tot++;
    // if (_tot >= n * 2 + 10) {
    //   std::cout << -1 << '\n';
    //   exit(0);
    // }
    for (int v : g[u]) {
      if (v != p) {
        gg[u].push_back(v);
        in[v]++;
        dfs2(v, u);
      }
    }
  }

void solve() {
  int n;
  std::cin >> n;
  // std::vector<std::vector<int>> g(n * 2 + 1);
  g.assign(n * 2 + 1, std::vector<int>());
  std::vector<int> a(n * 2 + 1);
  std::vector<int> lockpos(n + 1), keypos(n + 1);
  // std::vector<int> in(n * 2 + 1);
  in.assign(n * 2 + 1, 0);

  for (int i = 1; i <= n * 2; i++) {
    std::cin >> a[i];
    if (a[i] < 0) {
      lockpos[-a[i]] = i;
    } else {
      keypos[a[i]] = i;
    }
  }
  for (int i = 2; i <= n * 2; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> L(n * 2 + 1), R(n * 2 + 1), dep(n * 2 + 1);
  std::vector<std::vector<int>> up(31, std::vector<int>(n * 2 + 1));
  int tot = 0;
  int _tot = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    _tot++;
    if (_tot >= n * 2 + 10) {
      std::cout << -1 << '\n';
      exit(0);
    }
    L[u] = ++tot;
    dep[u] = dep[p] + 1;
    up[0][u] = p;
    for (int i = 1; i <= 30; i++) {
      up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    R[u] = tot;
  };
  dfs(dfs, 1, 0);
  std::vector<int> s(n * 2 + 2);
  auto ispa = [&](int x, int y) {
    if (dep[y] < dep[x]) {
      for (int i = 30; i >= 0; i--) {
        if (dep[up[i][x]] >= dep[y]) {
          x = up[i][x];
        }
      }
    }
    return x == y;
  };
  auto getpa = [&](int x, int d) {
    if (d <= 0) return x;
    for (int i = 30; i >= 0; i--) {
      if (d >> i & 1) {
        x = up[i][x];
      }
    }
    return x;
  };
  for (int i = 1; i <= n; i++) {
    if (!ispa(keypos[i], lockpos[i])) {
      s[L[lockpos[i]]]++;
      s[R[lockpos[i]] + 1]--;
    } else {
      int x = getpa(keypos[i], dep[keypos[i]] - dep[lockpos[i]] - 1);
      s[1]++;
      s[L[x]]--;
      s[R[x] + 1]++;
    }
  }
  for (int i = 1; i <= n * 2; i++) {
    s[i] += s[i - 1];
  }
  int u = 0;
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n * 2; i++) {
    if (a[i] > 0 && s[L[i]] == 0) {
      ans[a[i]] = 1;
      // std::cerr << i << ' ';
      u = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    in[lockpos[i]]++;
  }
  // std::cerr << '\n';
  if (u == 0) {
    for (int i = 0; i < n; i++) {
      std::cout << 0;
    }
    std::cout << '\n';
    return;
  }
  std::queue<int> q;
  q.push(u);
  in[u] = 0;
  std::vector<int> vis(n * 2 + 1);
  vis[u] = 1;
  // std::vector<std::vector<int>> gg(n * 2 + 1);
  gg.assign(n * 2 + 1, std::vector<int>());
  _tot = 0;
  // auto dfs2 = [&](auto self, int u, int p) -> void {
  // };
  // dfs2(dfs2, u, 0);
  dfs2(u, 0);
  _tot = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ++_tot;
    if (_tot >= n * 2 + 10) {
      std::cout << -1 << '\n';
      exit(0);
    }
    // std::cerr << u << ' ' << a[u] << '\n';
    if (a[u] > 0) {
      int v = lockpos[a[u]];
      in[v]--;
      if (in[v] == 0 && !vis[v]) {
        q.push(v);
        vis[v] = 1;
      }
    }
    for (int v : gg[u]) {
      --in[v];
      if (a[v] > 0 || in[v] == 0) {
        if (vis[v]) continue;
        vis[v] = 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n * 2; i++) {
    if (in[i] > 0) {
      for (int j = 0; j < n; j++) {
        std::cout << 0;
      }
      std::cout << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i];
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}