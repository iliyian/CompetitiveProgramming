#include <bits/stdc++.h>
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Solve {
  vector<vector<int>> g;
  int p[N], maxd[N << 2], mind[N << 2];
  int dep[N], rnk[N], dfn[N], son[N], top[N], siz[N], pa[N], cnt = 0;
  int n, q;

  void dfs1(int u) {
    for (int v : g[u]) {
      if (dep[v]) continue;
      dep[v] = dep[u] + 1;
      pa[v] = u;
      dfs1(v);
      siz[u] += siz[v];
      if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
    }
  }
  void dfs2(int u, int t) {
    top[u] = t;
    ++cnt;
    dfn[u] = cnt, rnk[cnt] = u;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u])
      if (v != pa[u] && v != son[u]) dfs2(v, v);
  }

  void pushup(int p) {
    maxd[p] = max(maxd[lc], maxd[rc]);
    mind[p] = min(mind[lc], mind[rc]);
  }
  void build(int s, int t, int p) {
    if (s == t) {
      maxd[p] = mind[p] = p[]
    }
    int mid = s + (t - s >> 1);
    build(s, mid, lc);
    build(mid + 1, t, rc);
    pushup(p);
  }
  int hldquerymax(int x) {

  }
  int hldquerymin(int x) {

  }
  void solve() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v), g[v].push_back(u);
    }
    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);

    build(1, n, 1);
    for (int i = 1; i <= n; i++)
      cin >> p[i];
    for (int i = 0; i < q; i++) {
      int l, r, x;
      cin >> l >> r >> x;
      int min = hldquerymin(x), max = hldquerymax(x);
      
      
      else cout << "NO\n";
    }
    cout << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G>in", "r", stdin);
  int _; cin >> _;
  while (_--) Solve{}.solve();
}