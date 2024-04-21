// date: 2024-03-19 12:27:11
// tag: 虚树，dp
// RE#01: mx和mn搞反了，isK数组大小搞错了

#include <bits/stdc++.h>
#define int long long
#define N 300005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Edge {
  int v, w;
};
vector<Edge> g[N], vg[N];
int dfn[N], pa[N], rnk[N], top[N], son[N], siz[N], mn[N << 2], val[N], dep[N];
int dfncnt = 0, n;
bitset<N> vis;

void dfs1(int u) {
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (dep[v]) continue;
    pa[v] = u;
    dep[v] = dep[u] + 1;
    val[v] = w;
    dfs1(v);
    siz[u] += siz[v];
    if (!son[u] || siz[son[u]] < siz[v]) {
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
  for (auto [v, w] : g[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = pa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}

void pushup(int p) {
  mn[p] = min(mn[lc], mn[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    mn[p] = val[rnk[l]];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

int querymin(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mn[p];
  int mid = (s + t) / 2, ans = INT_MAX;
  if (l <= mid) ans = min(ans, querymin(l, r, s, mid, lc));
  if (r > mid) ans = min(ans, querymin(l, r, mid + 1, t, rc));
  return ans;
}

int hldquerymin(int x, int y) {
  int ans = INT_MAX;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = min(ans, querymin(dfn[top[x]], dfn[x], 1, n, 1));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = min(ans, querymin(dfn[x] + 1, dfn[y], 1, n, 1));
  return ans;
}

bitset<N> isK;

bool cmp(const int &x, const int &y) {
  return dfn[x] < dfn[y];
}

void solve() {
  int k;
  cin >> k;
  vector<int> a(k + 1), ks(k);
  auto cmp = [&](int x, int y) {
    return dfn[x] < dfn[y];
  };
  a[0] = 1;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    ks[i - 1] = a[i];
    isK[ks[i - 1]] = true;
  }
  sort(a.begin(), a.end(), cmp);
  int len = a.size();
  for (int i = 1; i < len; i++) {
    a.push_back(lca(a[i], a[i - 1]));
  }
  sort(a.begin(), a.end(), cmp);
  len = unique(a.begin(), a.end()) - a.begin();
  vector<tuple<int, int, int>> edges;
  for (int i = 1; i < len; i++) {
    int la = lca(a[i], a[i - 1]);
    int w = hldquerymin(a[i], la);
    vg[la].push_back({a[i], w});
    // edges.push_back({a[i], la, w});
    // vg[a[i]].clear();
    // vg[la].clear();
  }
  // for (auto &[u, v, w] : edges) {
  //   vg[u].push_back({v, w});
  //   vg[v].push_back({u, w});
  // }
  vector<int> dp(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (auto [v, w] : vg[u]) {
      if (v == p) continue;
      self(self, v, u);
      if (isK[v]) dp[u] += w;
      else dp[u] += min(dp[v], w);
    }
    vg[u].clear();
  };
  dfs(dfs, 1, 0);
  cout << dp[1] << '\n';
  for (auto i : ks) {
    isK[i] = false;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  int m;
  cin >> m;
  for (int _ = 1; _ <= m; _++) {
    solve();
  }

  return 0;
}