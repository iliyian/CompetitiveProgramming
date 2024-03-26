// date: 2024-03-25 18:58:29
// tag: 树上差分

#include <bits/stdc++.h>
#define int long long
#define N 300005
using namespace std;

int a[N], d[N], sm[N];
int dep[N], siz[N], son[N], top[N], pa[N], dfn[N], rnk[N];
int dfncnt = 0;
vector<int> g[N];

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (dep[v]) continue;
    pa[v] = u;
    dep[v] = dep[u] + 1;
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
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

void dfs(int u) {
  for (int v : g[u]) {
    if (v != pa[u]) {
      dfs(v);
      d[u] += d[v];
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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  for (int i = 1; i < n; i++) {
    int s = a[i], t = a[i + 1];
    int lc = lca(s, t);
    d[s]++, d[lc]--;
    d[t]++, d[pa[lc]]--;
  }
  dfs(1);
  for (int i = 2; i <= n; i++) {
    d[a[i]]--; // 已经是原数组，交叠处的减法
  }
  for (int i = 1; i <= n; i++) {
    cout << d[i] << '\n';
  }

  return 0;
}