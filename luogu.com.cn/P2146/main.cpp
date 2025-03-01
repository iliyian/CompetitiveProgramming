// date: 2024-08-12 19:51:39
// tag: hld+seg，子树修改，区间统计

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

constexpr int N = 1e5;

int n;

std::vector<int> g[N + 1];
std::vector<int> dep(N + 1), siz(N + 1), rnk(N + 1), top(N + 1), dfn(N + 1), son(N + 1), pa(N + 1);
std::vector<int> d(N << 2), laz(N << 2, -1);
int dfncnt = 0;

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
  dfn[u] = ++dfncnt;
  rnk[dfncnt] = u;
  top[u] = t;
  if (!son[u]) {
    return;
  }
  dfs2(son[u], t);
  for (int v : g[u]) {
    if (v != son[u] && v != pa[u]) {
      dfs2(v, v);
    }
  }
}

void pushdown(int s, int t, int p) {
  if (laz[p] != -1) {
    d[lc] = (mid - s + 1) * laz[p];
    d[rc] = (t - mid) * laz[p];
    laz[lc] = laz[rc] = laz[p];
    laz[p] = -1;
  }
}

void pushup(int p) {
  d[p] = d[lc] + d[rc];
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) {
    return d[p];
  }
  pushdown(s, t, p);
  return query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc);
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    d[p] = (t - s + 1) * c, laz[p] = c;
    return;
  }
  pushdown(s, t, p);
  modify(l, r, s, mid, lc, c);
  modify(l, r, mid + 1, t, rc, c);
  pushup(p);
}

int hldquery(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    ans += query(dfn[top[x]], dfn[x], 1, n, 1);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  ans += query(dfn[x], dfn[y], 1, n, 1);
  return ans;
}

void hldmodify(int x, int y, int c) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    modify(dfn[top[x]], dfn[x], 1, n, 1, c);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  modify(dfn[x], dfn[y], 1, n, 1, c);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    x++;
    g[x].push_back(i);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  int q;
  std::cin >> q;
  while (q--) {
    std::string op;
    int x;
    std::cin >> op >> x;
    x++;
    if (op == "install") {
      std::cout << dep[x] - hldquery(1, x) << '\n';
      hldmodify(1, x, 1);
    } else {
      std::cout << query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1) << '\n';
      modify(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1, 0);
      // hldmodify(x, x + siz[x] - 1, 0);
    }
  }
  return 0;
}