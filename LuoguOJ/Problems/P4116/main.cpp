// date: 2024-03-20 11:40:13
// tag: 树链剖分
// wa#01-04: 线段树的query的if(r>mid)写成else了
// 

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 100005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

vector<int> g[N];
int dfn[N], rnk[N], siz[N], son[N], top[N], pa[N], dep[N];
int n, dfncnt = 0, mn[N << 2];

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (dep[v]) continue;
    dep[v] = dep[u] + 1;
    pa[v] = u;
    dfs1(v);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) {
      son[u] = v;
    }
  }
}

void dfs2(int u, int t) {
  top[u] = t;
  dfn[u] = ++dfncnt;
  rnk[dfncnt] = u;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int v : g[u]) {
    if (v != pa[u] && v != son[u])  {
      dfs2(v, v);
    }
  }
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mn[p];
  int mid = (s + t) / 2, ans = inf;
  if (l <= mid) ans = min(ans, query(l, r, s, mid, lc));
  if (r > mid) ans = min(ans, query(l, r, mid + 1, t, rc));
  return ans;
}

void pushup(int p) {
  mn[p] = min(mn[lc], mn[rc]);
}

void modify(int x, int s, int t, int p) {
  if (x == s && x == t) {
    mn[p] = (mn[p] == x ? inf : x);
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, s, mid, lc);
  else modify(x, mid + 1, t, rc);
  pushup(p);
}

int hldquery(int x, int y) {
  int ans = inf;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = min(ans, query(dfn[top[x]], dfn[x], 1, n, 1));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = min(ans, query(dfn[x], dfn[y], 1, n, 1));
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int q;
  cin >> n >> q;
  memset(mn, 0x3f, sizeof(mn));
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  for (int _ = 0; _ < q; _++) {
    int op, x;
    cin >> op >> x;
    if (!op) {
      modify(dfn[x], 1, n, 1);
    } else {
      int ans = hldquery(1, x);
      cout << (ans == inf ? -1 : rnk[ans]) << '\n';
    }
  }

  return 0;
}