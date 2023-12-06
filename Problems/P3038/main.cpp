// date: 2023/12/5
// tag: hld
// wa#01: windows下dfs1爆栈？
// wa#01: pushdown写错了,
// wa#01: hldadd中的dfn[top[x]]和dfn[x]写反了，父亲编号反而小，比较反常

#include <bits/stdc++.h>
#define N 100005
#define lc o << 1
#define rc o << 1 | 1
using namespace std;

int n, m, siz[N], son[N], top[N], pa[N], dfn[N], rnk[N], dep[N], cnt = 0;
int d[N << 2], laz[N << 2];

vector<vector<int>> g;

// void build(int s, int t, int o) {
//   if (s == t) {
//     d[o] = 0, 
//   }
// }

void pushdown(int s, int t, int o) {
  int mid = s + (t - s >> 1);
  d[lc] += (mid - s + 1) * laz[o], d[rc] += (t - mid) * laz[o];
  laz[lc] += laz[o], laz[rc] += laz[o];
  laz[o] = 0;
}

void pushup(int o) {
  d[o] = d[lc] + d[rc];
}

void add(int l, int r, int s, int t, int o, int c) {
  if (l <= s && t <= r) {
    d[o] += (t - s + 1) * c, laz[o] += c;
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(s, t, o);
  if (l <= mid) add(l, r, s, mid, lc, c);
  if (r > mid) add(l, r, mid + 1, t, rc, c);
  pushup(o);
}

int query(int l, int r, int s, int t, int o) {
  if (l <= s && t <= r) return d[o];
  int mid = s + (t - s >> 1), sum = 0;
  pushdown(s, t, o);
  if (l <= mid) sum += query(l, r, s, mid, lc);
  if (r > mid) sum += query(l, r, mid + 1, t, rc);
  return sum;
}

void dfs1(int u) {
  siz[u] = 1;
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
  dfn[u] = cnt;
  rnk[cnt] = u;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int v : g[u])
    if (son[u] != v && pa[u] != v) dfs2(v, v);
}

void hldadd(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    add(dfn[top[x]], dfn[x], 1, n, 1, 1);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  add(dfn[x] + 1, dfn[y], 1, n, 1, 1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  for (int i = 0; i < m; i++) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'P') hldadd(x, y);
    else {
      if (pa[x] != y) swap(x, y);
      cout << query(dfn[x], dfn[x], 1, n, 1) << '\n';     
    }
  }
}