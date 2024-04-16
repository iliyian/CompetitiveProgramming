// date: 2024-04-15 19:30:10
// tag: 动态开点线段树优化建图

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define inf 0x3f3f3f3f3f3f3f3f
#define lc seg[p].l
#define rc seg[p].r
using namespace std;

struct Edge {
  int v, w;
};
vector<Edge> g[N << 3];

struct Seg {
  int l, r;
} seg[N << 3];
int d[N], tot = 0, n;

void buildin(int l, int r, int &p) {
  p = ++tot;
  if (l == r) {
    d[l] = p;
    return;
  }
  int mid = (l + r) / 2;
  buildin(l, mid, lc);
  buildin(mid + 1, r, rc);
  g[p].push_back({lc, 0});
  g[p].push_back({rc, 0});
}

void buildout(int l, int r, int &p) {
  if (l == r) {
    p = d[l];
    return;
  }
  p = ++tot;
  int mid = (l + r) / 2;
  buildout(l, mid, lc);
  buildout(mid + 1, r, rc);
  g[lc].push_back({p, 0});
  g[rc].push_back({p, 0});
}

void addin(int l, int r, int s, int t, int p, int v, int w) {
  if (l <= s && t <= r) {
    g[v].push_back({p, w});
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) addin(l, r, s, mid, lc, v, w);
  if (r > mid) addin(l, r, mid + 1, t, rc, v, w);
}

void addout(int l, int r, int s, int t, int p, int v, int w) {
  if (l <= s && t <= r) {
    g[p].push_back({v, w});
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) addout(l, r, s, mid, lc, v, w);
  if (r > mid) addout(l, r, mid + 1, t, rc, v, w);
}

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
vector<int> dis(N << 3);
bitset<N << 3> vis;

void dijkstra(int s) {
  priority_queue<Node> q;
  fill(dis.begin(), dis.end(), inf);
  q.push({s, dis[s] = 0});
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &[v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v])
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

  int q, s;
  cin >> n >> q >> s;
  int rt1, rt2;
  buildin(1, n, rt1);
  buildout(1, n, rt2);
  for (int _ = 1; _ <= q; _++) {
    int op, v, u, l, r, w;
    cin >> op;
    if (op == 1) {
      cin >> v >> u >> w;
      g[d[v]].push_back({d[u], w});
    } else if (op == 2) {
      cin >> v >> l >> r >> w;
      addin(l, r, 1, n, rt1, d[v], w);
    } else {
      cin >> v >> l >> r >> w;
      addout(l, r, 1, n, rt2, d[v], w);
    }
  }

  dijkstra(d[s]);
  for (int i = 1; i <= n; i++) {
    cout << (dis[d[i]] == inf ? -1 : dis[d[i]]) << ' ';
  }

  return 0;
}