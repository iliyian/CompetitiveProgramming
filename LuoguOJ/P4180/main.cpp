// date: 2024/02/04 14:20:50
// tag: 树剖维护树上次大边权 及 严格次小生成树模板，还有边权转点权的技巧
// 
// wa#01: 调半天感情是线段树写错了,,,
// build赋d的初始值的时候直接用dfn在原图上了，而不是rnk值，
// 离谱，这都能过一半

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define pll pair<long long, long long>
#define lc p << 1
#define rc p << 1 | 1
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w < b.w;
  }
};
int id[N];

struct Ed {
  int v, w;
};
vector<vector<Ed>> g, mg;

int find(int x) {return x == id[x] ? x : id[x] = find(id[x]);}
int pa[N], siz[N], dep[N], rnk[N], dfn[N], top[N], son[N];
int dis[N], a[N];
pll d[N << 2];
int cnt = 0, n, m;
bitset<3 * N> vis;

void dfs1(int u, int prv) {
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (v == prv) continue;
    pa[v] = u;
    dep[v] = dep[u] + 1;
    dis[v] = dis[u] + w;
    dfs1(v, u);
    siz[u] += siz[v];
    if (!son[u] || siz[v] > siz[son[u]])
      son[u] = v;
  }
}

void dfs2(int u, int t) {
  ++cnt;
  top[u] = t;
  dfn[u] = cnt;
  rnk[cnt] = u;
  a[u] = dis[u] - dis[pa[u]];
  if (!son[u]) return;
  dfs2(son[u], t);
  for (auto [v, w]: g[u])
    if (v != son[u] && v != pa[u])
      // 不同链top不同的性质很不错
      dfs2(v, v);
}

int getsec(const pll &p1, const pll &p2) {
  int a[4] = {p1.first, p1.second, p2.first, p2.second};
  sort(a, a + 4, greater<int>());
  for (int i = 1; i < 4; i++)
    if (a[i] < a[0])
      return a[i];
  return -inf;
}

void build(int l, int r, int p) {
  if (l == r) {
    d[p] = {a[rnk[l]], a[rnk[l]]};
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);
  d[p].first = max(d[lc].first, d[rc].first);
  d[p].second = getsec(d[lc], d[rc]);
}

pll query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + (t - s >> 1);
  pll t1 = {-inf, -inf}, t2 = {-inf, -inf};
  if (l <= mid) t1 = query(l, r, s, mid, lc);
  if (r > mid) t2 = query(l, r, mid + 1, t, rc);
  return {max(t1.first, t2.first), getsec(t1, t2)};
}

int hldquery(int u, int v, int w) {
  pll ma = {-inf, -inf};
  while (top[u] != top[v]) {
    if (dfn[top[u]] < dfn[top[v]]) swap(u, v);
    pll temp = query(dfn[top[u]], dfn[u], 1, n, 1);
    u = pa[top[u]];
    ma.first = max(ma.first, temp.first);
    ma.second = getsec(ma, temp);
  }
  if (dfn[u] > dfn[v]) swap(u, v);
  pll temp = query(dfn[u] + 1, dfn[v], 1, n, 1);
  ma.first = max(temp.first, ma.first);
  ma.second = getsec(temp, ma);
  return ma.first == w ? ma.second : ma.first;
}

void solve() {
  cin >> n >> m;
  iota(id + 1, id + 1 + n, 1);
  vector<Edge> edges;
  g.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    // 不建图，只建树
  }
  sort(edges.begin(), edges.end());

  int cnt = 0, minsum = 0;
  for (int i = 0; i < edges.size(); i++) {
    Edge edge = edges[i];
    int u = edge.u, v = edge.v, w = edge.w;
    if (cnt == n - 1) break;
    if (find(u) != find(v)) {
      id[find(u)] = find(v);
      cnt++;
      g[u].push_back({v, w}), g[v].push_back({u, w});
      vis[i] = true;
      minsum += w;
    }
  }

  dfs1(1, 0);
  dfs2(1, 1);

  build(1, n, 1);

  int secsum = inf;
  for (int i = 0; i < edges.size(); i++) {
    if (vis[i]) continue;
    Edge edge = edges[i];
    int u = edge.u, v = edge.v, w = edge.w;
    // why?
    int newsum = minsum + w - hldquery(u, v, w);
    secsum = min(secsum, newsum);
  }
  cout << secsum << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}