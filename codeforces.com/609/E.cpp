// date: 2024-08-26 21:15:12
// tag: 必定要求某条边的mst

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

constexpr int N = 2e5;

std::vector<std::pair<int, int>> g[N + 1];
std::vector<std::array<int, 4>> edges(N + 1);
std::vector<int> id(N + 1);
std::vector<int> pa(N + 1), dep(N + 1), siz(N + 1), rnk(N + 1), dfn(N + 1), son(N + 1), top(N + 1);
std::vector<int> ismain(N + 1), mx(N << 2), a(N + 1);
int dfncnt = 0, n, m;

int find(int x) {return x == id[x] ? x : id[x] = find(id[x]);}

void dfs1(int u) {
  siz[u] = 1;
  for (auto &[v, w] : g[u]) {
    if (!dep[v]) {
      dep[v] = dep[u] + 1;
      pa[v] = u;
      a[v] = w;
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
  for (auto &[v, w] : g[u]) {
    if (v != son[u] && v != pa[u]) {
      dfs2(v, v);
    }
  }
}

void pull(int p) {
  mx[p] = std::max(mx[lc], mx[rc]);
}

void build(int s, int t, int p) {
  if (s == t) {
    mx[p] = a[rnk[s]];
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return mx[p];
  return std::max(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

int hldquery(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    ans = std::max(ans, query(dfn[top[x]], dfn[x], 1, n, 1));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  ans = std::max(ans, query(dfn[x] + 1, dfn[y], 1, n, 1));
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    edges[i] = {w, x, y, i};
  }
  std::sort(edges.begin() + 1, edges.begin() + m + 1);
  int cnt = 0, sum = 0;
  std::iota(id.begin() + 1, id.begin() + n + 1, 1);
  for (int i = 1; i <= m && cnt < n - 1; i++) {
    auto [w, x, y, _] = edges[i];
    if (find(x) != find(y)) {
      id[find(x)] = find(y);
      cnt++;
      sum += w;
      g[x].push_back({y, w});
      g[y].push_back({x, w});
    }
  }

  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);

  std::vector<int> ans(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[w, x, y, id] = edges[i];
    if (pa[x] == y || pa[y] == x) {
      ans[id] = sum;
      continue;
    }
    ans[id] = sum + w - hldquery(x, y);
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << '\n';
  }

  return 0;
}