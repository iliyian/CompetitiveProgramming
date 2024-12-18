// date: 2024-07-16 15:30:30
// tag: 动态开点线段树，hld

#include <bits/stdc++.h>
#define lc seg[p].ls
#define rc seg[p].rs
constexpr int N = 1e5;

std::vector<std::vector<int>> g(N + 1);
std::vector<int> dep(N + 1), pa(N + 1), siz(N + 1), son(N + 1), rnk(N + 1), dfn(N + 1), top(N + 1);
int dfn_cnt = 0, n, q;

struct Seg {
  int ls = 0, rs = 0, sum = 0, mx = 0;
} seg[20040419];

std::vector<int> rt(N + 1), W(N + 1), C(N + 1);
int tot = 0;

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (!dep[v]) {
      dep[v] = dep[u] + 1;
      pa[v] = u;
      dfs1(v);
      siz[u] += siz[v];
      if (siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
  }
}

void dfs2(int u, int t) {
  dfn[u] = ++dfn_cnt;
  rnk[dfn_cnt] = u;
  top[u] = t;
  if (!son[u]) {
    return;
  }
  dfs2(son[u], t);
  for (int v : g[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

void pushup(int p) {
  seg[p].sum = seg[lc].sum + seg[rc].sum;
  seg[p].mx = std::max(seg[lc].mx, seg[rc].mx);
}

void modifyW(int x, int s, int t, int &p, int w) {
  if (!p) p = ++tot;
  if (x == s && s == t) {
    seg[p].sum = seg[p].mx = w;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modifyW(x, s, mid, lc, w);
  else modifyW(x, mid + 1, t, rc, w);
  pushup(p);
}

int querymx(int l, int r, int s, int t, int &p) {
  if (!p) return 0;
  if (l <= s && t <= r) {
    return seg[p].mx;
  }
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans = std::max(ans, querymx(l, r, s, mid, lc));
  if (r > mid) ans = std::max(ans, querymx(l, r, mid + 1, t, rc));
  return ans;
}

int querysum(int l, int r, int s, int t, int &p) {
  if (!p) return 0;
  if (l <= s && t <= r) {
    return seg[p].sum;
  }
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans += querysum(l, r, s, mid, lc);
  if (r > mid) ans += querysum(l, r, mid + 1, t, rc);
  return ans;
}

void build(int l, int r, int &p, int c) {
  if (!p) p = ++tot;
  if (l == r) {
    seg[p].sum = seg[p].mx = (C[rnk[l]] == c ? W[rnk[l]] : 0);
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc, c);
  build(mid + 1, r, rc, c);
  pushup(p);
}

int hldquerysum(int x, int y) {
  int ans = 0, c = C[x];
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    ans += querysum(dfn[top[x]], dfn[x], 1, n, rt[c]);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  ans += querysum(dfn[x], dfn[y], 1, n, rt[c]);
  return ans;
}

int hldquerymx(int x, int y) {
  int ans = 0, c = C[x];
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    ans = std::max(ans, querymx(dfn[top[x]], dfn[x], 1, n, rt[c]));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  ans = std::max(ans, querymx(dfn[x], dfn[y], 1, n, rt[c]));
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::cin >> n >> q;

  std::bitset<N + 1> vis;
  for (int i = 1; i <= n; i++) {
    std::cin >> W[i] >> C[i];
    vis[C[i]] = true;
  }

  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  
  for (int i = 1; i <= n; i++) {
    modifyW(dfn[i], 1, n, rt[C[i]], W[i]);
  }

  while (q--) {
    std::string op;
    int x, y;
    std::cin >> op >> x >> y;
    if (op == "CC") {
      modifyW(dfn[x], 1, n, rt[C[x]], 0);
      C[x] = y;
      modifyW(dfn[x], 1, n, rt[C[x]], W[x]);
    } else if (op == "CW") {
      modifyW(dfn[x], 1, n, rt[C[x]], y);
      W[x] = y;
    } else if (op == "QS") {
      std::cout << hldquerysum(x, y) << '\n';
    } else if (op == "QM") {
      std::cout << hldquerymx(x, y) << '\n';
    }
  }

  return 0;
}