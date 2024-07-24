#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> c(n + 1);
  set<pair<int, int>, greater<pair<int, int>>> s;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> dep(n + 1), siz(n + 1), top(n + 1), son(n + 1), pa(n + 1), dfn(n + 1), rnk(n + 1);
  int dfncnt = 0;
  auto dfs1 = [&](auto self, int u) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (!dep[v]) {
        dep[v] = dep[u] + 1;
        pa[v] = u;
        self(self, v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) {
          son[u] = v;
        }
      }
    }
  };
  auto dfs2 = [&](auto self, int u, int t) -> void {
    top[u] = t;
    dfn[u] = ++dfncnt;
    rnk[dfncnt] = u;
    if (!son[u]) return;
    self(self, son[u], t);
    for (int v : g[u]) {
      if (v != pa[u] && v != son[u]) {
        self(self, v, v);
      }
    }
  };
  dep[1] = 1;
  dfs1(dfs1, 1);
  dfs2(dfs2, 1, 1);

  vector<int> d((n + 5) << 2);

  auto pushup = [&](int p) {
    d[p] = d[lc] + d[rc];
  };

  auto build = [&](auto self, int l, int r, int p) {
    if (l == r) {
      d[p] = c[rnk[l]];
      return;
    }
    int mid = (l + r) / 2;
    self(self, l, mid, lc);
    self(self, mid + 1, r, rc);
    pushup(p);
  };
  build(build, 1, n, 1);

  auto query = [&](auto self, int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int mid = (s + t) / 2, ans = 0;
    if (l <= mid) ans += self(self, l, r, s, mid, lc);
    if (r > mid) ans += self(self, l, r, mid + 1, t, rc);
    return ans;
  };

  auto rev = [&](auto self, int x, int s, int t, int p) -> void {
    if (x == s && x == t) {
      d[p] ^= 1;
      return;
    }
    int mid = (s + t) / 2, ans = 0;
    if (x <= mid) self(self, x, s, mid, lc);
    else self(self, x, mid + 1, t, rc);
    pushup(p);
  };

  for (int i = 1; i <= n; i++) {
    if (c[i]) {
      s.insert({dep[i], i});
    }
  }

  auto lca = [&](int x, int y) {
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      x = pa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
  };

  auto hldquery = [&](int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      ans += query(query, dfn[top[x]], dfn[x], 1, n, 1);
      x = pa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += query(query, dfn[x], dfn[y], 1, n, 1);
    return ans;
  };

  for (int _ = 1; _ <= q; _++) {
    int u;
    cin >> u;
    int v = query(query, dfn[u], dfn[u], 1, n, 1);
    rev(rev, dfn[u], 1, n, 1);

    if (v) {
      s.erase({dep[u], u});
    } else {
      s.insert({dep[u], u});
    }

    if (s.size() < 2) {
      cout << "No\n";
      continue;
    }
    
    int x = s.begin()->first;
    bool f = true;

    while (x != 1) {
      if (!c[x]) {
        cout << "Yes\n";
        goto nxt;
      }
      int exp = dfn[top[x]] - dfn[x] + 1;
      if (exp != query(query, dfn[top[x]], dfn[x], 1, n, 1)) {
        cout << "No\n";
        goto nxt;
      }
      x = pa[top[x]];
    }

    

    nxt:;
  }

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}