// date: 2024-04-15 18:05:17
// tag: 线段树优化建图，dfs
// wa#01: dis从N<<2开到N<<3后忘记改dijkstra里面fill的范围了

#include <bits/stdc++.h>
#define int long long
#define N 300005
#define lc p << 1
#define rc p << 1 | 1
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};
vector<Edge> g[N << 3];
int d[N * 2 + 1], raw[N << 3], prv[N << 3], n;

void build(int l, int r, int p) {
  if (l == r) {
    d[l] = p;
    raw[p] = l;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  g[p].push_back({lc, 0});
  g[p].push_back({rc, 0});
}

void add(int l, int r, int s, int t, int p, int u, int w) {
  if (l <= s && t <= r) {
    g[u].push_back({p, w});
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) add(l, r, s, mid, lc, u, w);
  if (r > mid) add(l, r, mid + 1, t, rc, u, w);
}

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
int dis[N << 3];
bitset<N << 3> vis;

void dijkstra(int s) {
  fill(dis, dis + (N << 3), inf);
  priority_queue<Node> q;
  q.push({s, dis[s] = 0});
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (u == d[0]) {
      return;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &[v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        prv[v] = u;
        q.push({v, dis[v]});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  build(0, n * 2, 1);
  for (int i = 1; i <= n; i++) {
    g[d[i]].push_back({d[i + b[i] + n], 0});
  }
  for (int i = 1; i <= n; i++) {
    add(i - a[i], i, 0, n * 2, 1, d[i + n], 1);
  }

  dijkstra(d[n * 2]);
  if (dis[d[0]] == inf) {
    cout << -1 << '\n';
    return 0;
  }

  cout << dis[d[0]] << '\n';
  stack<int> ans;
  for (int i = d[0]; i != d[n * 2]; i = prv[i]) {
    if (raw[i] <= n && raw[i]) {
      ans.push(raw[i]);
    }
  }
  while (!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
  cout << 0 << '\n';

  return 0;
}