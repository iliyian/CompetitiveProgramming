// date: 2024-12-09 14:09:07
// tag: 欧拉序将lca转换为根据dep的区间rmq询问，可以做到O(1)回答

#include <bits/stdc++.h>

void solve() {
  int n, m, s;
  std::cin >> n >> m >> s;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int tot = 0;
  std::vector<int> dfn(n + 1), rnk(n * 2), dep(n * 2); // tot == 2 * n - 1

  auto dfs = [&](auto self, int u, int p, int d) -> void {
    dfn[u] = ++tot;
    rnk[tot] = u;
    dep[tot] = d;
    for (int v : g[u]) {
      if (v != p && !dfn[v]) {
        self(self, v, u, d + 1);
        rnk[++tot] = u, dep[tot] = d; // 回溯继续加
      }
    }
  };
  dfs(dfs, s, 0, 1);

  std::vector<std::vector<int>> st(20, std::vector<int>(tot + 1)), rev(20, std::vector<int>(tot + 1));
  // rev 本质上是多阶的范围rnk，rnk把dfn转换成u
  for (int i = 1; i <= tot; i++) {
    st[0][i] = dep[i], rev[0][i] = rnk[i];
  }

  for (int i = 1; i <= 19; i++) {
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

  auto query = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    if (st[len][l] < st[len][r - (1 << len) + 1]) {
      return rev[len][l];
    } else {
      return rev[len][r - (1 << len) + 1];
    }
  };

  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (dfn[x] > dfn[y]) std::swap(x, y);
    std::cout << query(dfn[x], dfn[y]) << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
