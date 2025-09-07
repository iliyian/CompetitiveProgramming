#include <bits/stdc++.h>
#define int long long

// int lcm(int a, int b) {
//   return a * b / std::gcd(a, b);
// }

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> p, e;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) x /= i, cnt++;
      p.push_back(i);
      e.push_back(cnt);
    }
  }
  if (x > 1) {
    p.push_back(x);
    e.push_back(1);
  }
  int w = p.size();
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> a(n + 1), fals(n + 1);
  std::vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 0; j < p.size(); j++) { // O(logn)的
      int cnt = 0;
      while (a[i] % p[j] == 0) {
        a[i] /= p[j], cnt++;
      }
      if (cnt > e[j]) { // 某个质因数过多
        fals[i] = 1;
      }
      if (cnt == e[j]) { // 可行
        c[i] ^= 1 << j;
      }
    }
    if (a[i] > 1) { // 存在其他质因数
      fals[i] = 1;
    }
  }
  std::vector<int> vis(n + 1), maxx(n + 1), siz(n + 1);
  int tot = n, rt = 0, ans = 0;
  maxx[0] = LLONG_MAX / 3;
  auto getrt = [&](auto self, int u, int p) -> void {
    if (vis[u] || fals[u]) return;
    siz[u] = 1;
    maxx[u] = 0;
    for (int v : g[u]) {
      if (v != p && !vis[v] && !fals[v]) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], tot - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };
  std::vector<int> old, cur, oldval(1 << w), need;
  auto dfs = [&](auto self, int u, int p, int val) -> void {
    if (vis[u] || fals[u]) return;
    cur.push_back(val);
    for (int v : g[u]) {
      if (v != p && !vis[v] && !fals[v]) {
        self(self, v, u, val | c[v]);
      }
    }
  };
  // int _tot = 0;
  auto work = [&](auto self, int u, int p) -> void {
    if (vis[u] || fals[u]) return;
    // std::cerr << u << '\n';
    // _tot++;
    vis[u] = 1;
    oldval[0] = 1;
    if (c[u] == (1 << w) - 1) {
      ans++;
    }
    for (int v : g[u]) {
      if (v != p && !vis[v] && !fals[v]) {
        dfs(dfs, v, u, c[v] | c[u]);
        for (int i = 0; i < cur.size(); i++) {
          for (int S = 0; S < (1 << w); S++) {
            if ((cur[i] | S) == (1 << w) - 1) {
              ans += oldval[S];
            }
          }
        }
        while (!cur.empty()) {
          oldval[cur.back()]++;
          old.push_back(cur.back());
          cur.pop_back();
        }
      }
    }
    while (!old.empty()) {
      oldval[old.back()] = 0; old.pop_back();
    }
    for (int v : g[u]) {
      if (v != p && !vis[v] && !fals[v]) {
        tot = siz[v];
        rt = 0;
        getrt(getrt, v, u);
        self(self, rt, 0);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    tot = n;
    rt = 0;
    getrt(getrt, i, 0);
    work(work, rt, 0);
  }
  std::cout << ans << '\n';
  // std::cerr << _tot << '\n';
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