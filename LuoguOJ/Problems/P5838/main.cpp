// date: 2024-08-12 20:54:59
// tag: hld二分查询值的存在性

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e5;

std::vector<int> g[N + 1], col[N + 1];
std::vector<int> a(N + 1);
std::vector<int> dep(N + 1), siz(N + 1), top(N + 1), son(N + 1), pa(N + 1), rnk(N + 1), dfn(N + 1);
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
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int v : g[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

bool query(int l, int r, int c) {
  auto p = std::lower_bound(col[c].begin(), col[c].end(), l);
  if (p != col[c].end() && *p <= r) {
    return true;
  }
  return false;
}

int hldquery(int x, int y, int c) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y); 
    if (query(dfn[top[x]], dfn[x], c)) {
      return true;
    }
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  if (query(dfn[x], dfn[y], c)) return true;
  return false;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
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
  for (int i = 1; i <= n; i++) {
    col[a[i]].push_back(dfn[i]);
  }
  for (int i = 1; i <= n; i++) {
    std::sort(col[i].begin(), col[i].end()); 
  }
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    std::cin >> x >> y >> c;
    std::cout << (int)hldquery(x, y, c);
  }

  return 0;
}