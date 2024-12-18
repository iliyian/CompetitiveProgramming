// date: 2024-08-12 16:04:44
// tag: hld

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

constexpr int N = 1e5;

std::vector<int> dep(N + 1), siz(N + 1), son(N + 1), pa(N + 1), top(N + 1), dfn(N + 1), rnk(N + 1);
std::vector<int> g[N + 1], a(N + 1);

int dfncnt = 0, n, q;

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
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int v : g[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

std::vector<int> d(N << 2);
void pushup(int p) {
  d[p] = d[lc] ^ d[rc];
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[rnk[s]];
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pushup(p);
}

void modify(int x, int s, int t, int p, int c) {
  if (x == s && x == t) {
    d[p] = c;
    return;
  }
  if (x <= mid) modify(x, s, mid, lc, c);
  else modify(x, mid + 1, t, rc, c);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) {
    return d[p];
  }
  return query(l, r, s, mid, lc) ^ query(l, r, mid + 1, t, rc);
}

int hldquery(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    ans ^= query(dfn[top[x]], dfn[x], 1, n, 1);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  return ans ^ query(dfn[x], dfn[y], 1, n, 1);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      modify(dfn[x], 1, n, 1, y);
    } else {
      std::cout << hldquery(x, y) << '\n';
    }
  }

  return 0;
}