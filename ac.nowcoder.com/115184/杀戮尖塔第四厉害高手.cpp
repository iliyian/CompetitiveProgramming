#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dep(n + 1, -1);
  std::queue<int> q;
  q.push(1);
  dep[1] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (dep[v] == -1) {
        dep[v] = dep[u] + 1;
        q.push(v);
      }
    }
  }
  std::vector<std::array<int, 4>> f(n + 1);
  std::vector<std::array<int, 4>> mx(n + 1);
  if (x < a[1]) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    f[i].fill(LLONG_MIN / 3);
    mx[i].fill(LLONG_MIN / 3);
  }
  x += b[1];
  f[1][3] = x;
  mx[1][3] = x;
  std::vector<std::vector<int>> gg(n + 1);
  std::vector<int> in(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int v : g[i]) {
      if (dep[v] > dep[i]) {
        gg[i].push_back(v);
        in[v]++;
      } else {
        gg[v].push_back(i);
        in[i]++;
      }
    }
  }
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : gg[u]) {
      --in[v];
      for (int i = 0; i <= 3; i++) {
        if (a[v] <= f[u][i]) {
          f[v][i] = std::max(f[v][i], f[u][i] + b[v]);
        }
        if (i) {
          if (mx[dep[u]][i] >= a[v]) {
            f[v][i - 1] = std::max(f[v][i - 1], mx[dep[u]][i] + b[v]);
          }
        }
        mx[dep[v]][i] = std::max(mx[dep[v]][i], f[v][i]);
      }
      if (in[v] == 0) {
        q.push(v);
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= 3; j++) {
  //     std::cout << f[i][j] << ' ';
  //   }
  //   // std::cout << mx[]
  //   std::cout << '\n';
  // }
  for (int i = 0; i <= 3; i++) {
    if (f[n][i] != LLONG_MIN / 3) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
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