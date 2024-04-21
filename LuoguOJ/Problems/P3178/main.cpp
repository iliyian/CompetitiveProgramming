// date: 2023/12/6
// tag: hld template
// wa#01,02,03 没开long long, ls和rs写错

#include <bits/stdc++.h>
#define N 100005

// tmd 我是打死都想不到调了半天是ls和rs写错了
#define ls p << 1
#define rs p << 1 | 1

#define int long long
using namespace std;

int a[N], d[N << 2], laz[N << 2], n, m;
int siz[N], dep[N], pa[N], top[N], dfn[N], son[N], rnk[N], cnt = 0;

vector<vector<int>> g;

void pushup(int p) {
  d[p] = d[ls] + d[rs];
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[rnk[s]];
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, ls);
  build(mid + 1, t, rs);
  pushup(p);
}

void pushdown(int s, int t, int p) {
  int mid = s + (t - s >> 1);
  d[ls] += (mid - s + 1) * laz[p], d[rs] += (t - mid) * laz[p];
  laz[ls] += laz[p], laz[rs] += laz[p];
  laz[p] = 0;
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, laz[p] += c;
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(s, t, p);
  if (l <= mid) add(l, r, s, mid, ls, c);
  if (r > mid) add(l, r, mid + 1, t, rs, c);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + (t - s >> 1), sum = 0;
  pushdown(s, t, p);
  if (l <= mid) sum += query(l, r, s, mid, ls);
  if (r > mid) sum += query(l, r, mid + 1, t, rs);
  return sum;
}

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (dep[v]) continue;
    dep[v] = dep[u] + 1;
    pa[v] = u;
    dfs1(v);
    // tmd, u v 写反
    siz[u] += siz[v];
    if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
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

// 操作的不是dfn序而是实际编号
// 在此题没有用
// 直接操作dfn的只和seg有关，和hld无关

// void hldadd(int x, int y, int c) {
//   while (top[x] != top[y]) {
//     if (dep[top[x]] < dep[top[y]]) swap(x, y);
//     add(dfn[top[x]], dfn[x], 1, n, 1, c);
//     x = pa[top[x]];
//   }
//   if (dep[x] > dep[y]) swap(x, y);
//   add(dfn[x], dfn[y], 1, n, 1, c);
// }

int hldquery(int x, int y) {
  int sum = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    sum += query(dfn[top[x]], dfn[x], 1, n, 1);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  sum += query(dfn[x], dfn[y], 1, n, 1);
  return sum;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int op, x, a;
    cin >> op;
    if (op == 1) {
      cin >> x >> a;
      add(dfn[x], dfn[x], 1, n, 1, a);
    } else if (op == 2) {
      cin >> x >> a;
      // siz[]的真正意义，是子树序，真是和谐
      // 不需要hld函数内转移
      // 应该等同于 hldadd(x, rnk[dfn[x] + siz[x] - 1], a)
      // 毕竟 rnk[dfn[x]] = x;
      add(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1, a);
    } else {
      cin >> x;
      cout << hldquery(rnk[1], x) << '\n';
    }
  }
}