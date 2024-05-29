// date: 2024-05-24 18:38:47
// tag: lca，分类讨论

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> col(n + 1), g(n + 1);
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    col[c].push_back(i);
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }

  vector<vector<int>> pa(n + 1, vector<int>(23));
  vector<int> dep(n + 1), siz(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u][0] = p;
    siz[u] = 1;
    for (int i = 1; i <= 22; i++) {
      pa[u][i] = pa[pa[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs(dfs, 1, 0);

  auto ispa = [&](int x, int p) {
    int dis = dep[x] - dep[p];
    for (int i = 22; i >= 0; i--) {
      if (dis >> i & 1) {
        x = pa[x][i];
      }
    }
    return x == p;
  };

  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 22; i >= 0; i--) {
      if (dep[x] - (1 << i) >= dep[y]) {
        x = pa[x][i];
      }
    }
    if (x == y) return x;
    for (int i = 22; i >= 0; i--) {
      if (pa[x][i] != pa[y][i]) {
        x = pa[x][i], y = pa[y][i];
      }
    }
    return pa[x][0];
  };

  for (int _ = 1; _ <= n; _++) {
    auto &c = col[_];
    if (c.empty()) {
      cout << n * (n - 1) / 2 << '\n';
    } else if (c.size() == 1) {
      int ans = (n - siz[c[0]] + 1) * siz[c[0]] - 1;
      for (int i = 0; i < g[c[0]].size(); i++) {
        for (int j = i + 1; j < g[c[0]].size(); j++) {
          if (g[c[0]][i] != pa[c[0]][0] && g[c[0]][j] != pa[c[0]][0]) {
            ans += siz[g[c[0]][i]] * siz[g[c[0]][j]];
          }
        }
      }
      cout << ans << '\n';
    } else {
      sort(c.begin(), c.end(), [&](const int &x, const int &y) {
        return dep[x] > dep[y];
      });
      int y = 0;
      for (int i = 1; i < c.size(); i++) {
        if (!ispa(c.front(), c[i])) {
          y = i;
          break;
        }
      }

      if (!y) {
        // 链之间的点的其他子节点也是不可行的
        // cout << (n - siz[c.front()] - (dep[c.front()] - dep[c.back()]) + 1) * siz[c.front()] << '\n';
        
        int k = c.front();
        for (int i = 22; i >= 0; i--) {
          if (dep[k] - (1 << i) > dep[c.back()]) {
            k = pa[k][i];
          }
        }
        cout << (n - siz[k]) * siz[c.front()] << '\n';
      } else {
        int lc = lca(c.front(), c[y]);
        bool f = true;
        for (int i = 1; i < c.size(); i++) {
          if (i == y) continue;
          if (!ispa(c.front(), c[i]) && !ispa(c[y], c[i]) || dep[c[i]] < dep[lc]) {
            f = false;
            break;
          }
        }
        cout << (f ? siz[c.front()] * siz[c[y]] : 0) << '\n';
      }
    }
  }

  return 0;
}