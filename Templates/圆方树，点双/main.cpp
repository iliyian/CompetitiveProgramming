// date: 2024-07-17 09:59:02
// tag: 圆方树，点双连通分量

#include <bits/stdc++.h>
#define int long long
#define lc seg[p].ls
#define rc seg[p].rs
// using namespace std;

constexpr int N = 2e5;

std::vector<std::vector<int>> g(N + 1), G(N + 1);
std::vector<int> w(N + 1);
std::vector<int> top(N + 1), siz(N + 1), rnk(N + 1), dfn(N + 1), son(N + 1), dep(N + 1), pa(N + 1);
int dfncnt = 0, n, m, q;
std::vector<std::multiset<int>> S(N + 1);

void dfs1(int u) {
  siz[u] = 1;
  for (int v : G[u]) {
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
  for (int v : G[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

std::vector<int> tdfn(N + 1), low(N + 1), st(N + 1);
std::bitset<N + 1> ins;
int tcnt = 0, bcc = n, tp;

void tarjan(int u) {
  low[u] = tdfn[u] = ++tcnt;
  ins[u] = true;
  st[++tp] = u;
  for (int v : g[u]) {
    if (!tdfn[v]) {
      tarjan(v);
      low[u] = std::min(low[u], low[v]);
      if (low[v] == tdfn[u]) {
        ++bcc;
        for (int x = 0; x != v; --tp) {
          x = st[tp];
          // std::cout << x << ' ';
          G[bcc].push_back(x);
          G[x].push_back(bcc);
        }
        // std::cout << u << '\n';
        G[bcc].push_back(u);
        G[u].push_back(bcc);
      }
    } else {
      low[u] = std::min(low[u], tdfn[v]);
    }
  }
}

struct Seg {
  int ls, rs, mn = LLONG_MAX;
} seg[N << 2];
int segtot = 0, rt = 0;

void pushup(int p) {
  seg[p].mn = std::min(seg[lc].mn, seg[rc].mn);
}

void modify(int x, int s, int t, int &p, int c) {
  if (!p) p = ++segtot;
  if (x == s && x == t) {
    seg[p].mn = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, s, mid, lc, c);
  else modify(x, mid + 1, t, rc, c);
  pushup(p);
}

void build(int l, int r, int &p) {
  if (!p) p = ++segtot;
  if (l == r) {
    seg[p].mn = w[rnk[l]];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

int query(int l, int r, int s, int t, int &p) {
  if (!p) return LLONG_MAX;
  if (l <= s && t <= r) {
    return seg[p].mn;
  }
  int mid = (s + t) / 2, ans = LLONG_MAX;
  if (l <= mid) ans = std::min(ans, query(l, r, s, mid, lc));
  if (r > mid) ans = std::min(ans, query(l, r, mid + 1, t, rc));
  return ans;
}

int hldquery(int x, int y) {
  int ans = LLONG_MAX;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    ans = std::min(ans, query(dfn[top[x]], dfn[x], 1, bcc, rt));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  ans = std::min(ans, query(dfn[x], dfn[y], 1, bcc, rt));
  if (x > n) ans = std::min(ans, w[pa[x]]); // pa[x]\belong
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  std::cin >> n >> m >> q;
  bcc = n;

  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  tarjan(1);

  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);

  for (int i = 1; i <= n; i++) {
    if (pa[i]) {
      S[pa[i]].insert(w[i]);
    }
  }

  for (int i = n + 1; i <= bcc; i++) {
    w[i] = *S[i].begin();
  }

  build(1, bcc, rt);

  while (q--) {
    char op;
    int x, y;
    std::cin >> op >> x >> y;
    if (op == 'C') {
      modify(dfn[x], 1, bcc, rt, y);
      if (pa[x]) {
        S[pa[x]].erase(S[pa[x]].find(w[x]));
        S[pa[x]].insert(y);

        if (w[pa[x]] != *S[pa[x]].begin()) {
          w[pa[x]] = *S[pa[x]].begin();
          modify(dfn[pa[x]], 1, bcc, rt, w[pa[x]]);
        }
      }
      w[x] = y;
    } else {
      std::cout << hldquery(x, y) << '\n';
    }
  }

  return 0;
}