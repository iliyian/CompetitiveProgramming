// date: 2024-12-09 16:14:51
// tag: mex的二分，O(1)LCA，特判，树上问题的线性转化

#include <bits/stdc++.h>
#define int long long

constexpr int N = 5e5;

std::vector<std::pair<int, int>> g[N + 1];
int st[21][N * 2], rev[21][N * 2], rnk[N * 2], dep[N * 2], dfn[N + 1], a[N + 1], dia1[N + 1], dia2[N + 1];
int dist[N + 1];
int n, q, tot = 0;

int query(int x, int y) {
  int l = dfn[x], r = dfn[y];
  if (l > r) std::swap(l, r);

  int len = std::__lg(r - l + 1);
  if (st[len][l] < st[len][r - (1 << len) + 1]) {
    return rev[len][l];
  } else {
    return rev[len][r - (1 << len) + 1];
  }
}

int dis(int x, int y) {
  return dist[x] + dist[y] - 2 * dist[query(x, y)];
  // return dep[dfn[x]] + dep[dfn[y]] - 2 * dep[dfn[query(x, y)]];
}

int checkmaxd(int mid, int x) {
  if (mid == 0) return 0;
  return std::max(dis(dia1[mid], x), dis(dia2[mid], x));
};

void dfs(int u, int p, int d) {
  dfn[u] = ++tot;
  rnk[tot] = u;
  dep[tot] = d;
  for (auto [v, w] : g[u]) {
    if (v != p && !dfn[v]) {
      dist[v] = dist[u] + w;
      dfs(v, u, d + 1);
      rnk[++tot] = u, dep[tot] = d;
    }
  }
};

void euler() {
  dfs(1, 0, 1);
  for (int i = 1; i <= tot; i++) {
    st[0][i] = dep[i], rev[0][i] = rnk[i];
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j + (1 << i) - 1 <= tot; j++) {
      if (st[i - 1][j] < st[i - 1][j + (1 << (i - 1))]) {
        rev[i][j] = rev[i - 1][j];
        st[i][j] = st[i - 1][j];
      } else {
        rev[i][j] = rev[i - 1][j + (1 << (i - 1))];
        st[i][j] = st[i - 1][j + (1 << (i - 1))];
      }
    }
  }
}

void solve() {
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  if (n == 1) {
    // std::cout << q << '\n';
    while (q--) {
      int x, k;
      std::cin >> x >> k;
      std::cout << (a[1] ? 0 : 1) << '\n';
    }
    return;
  }

  euler();

  dia1[1] = dia2[1] = dia1[2] = p[1];
  dia2[2] = p[2];
  for (int i = 3; i <= n; i++) {
    dia1[i] = dia1[i - 1], dia2[i] = dia2[i - 1];
    int &x = dia1[i], &y = dia2[i];
    if (dis(x, p[i]) > dis(y, p[i])) std::swap(x, y);
    if (dis(p[i], y) > dis(x, y)) {
      x = p[i];
    }
  }

  std::vector<int> mex(n + 1);
  int cur = 1;
  while (a[p[cur]] == cur - 1) {
    cur++;
  }

  while (q--) {
    int x, k;
    std::cin >> x >> k;
    int l = 0, r = cur - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (checkmaxd(mid, x) <= k) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    // if (ans == n) {
    //   ans = mex;
    // }
    // if (ans == 1) {
    //   ans = (a[x] ? 0 : 1);
    // }
    std::cout << ans << '\n';
    // if (ans == 59) {
      // std::cout << checkmaxd(59, x) << '\n';
      // std::cout << dis(p[59], x) << '\n';
      // std::cout << a[p[59]] << '\n';
      // std::cout << x << ' ' << k << '\n';
    //   for (int i = 1; i <= n; i++) {
    //     std::cout << a[i] << ' ' << p[i] << '\n';
    //   }
    //   // std::cout << '\n';
    // }
    // std::cout << mex[ans] << '\n';
  }
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
