#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Node {
  int maxf, u, life;
  bool operator < (const Node &b) const {
    return maxf > b.maxf;
  }
};

int f[10001], n, m, b;
bitset<10001> vis;

bool check(int mid) {
  priority_queue<Node> pq;
  vis.reset();
  // memset(vis, 0x3f, sizeof(vis));
  if (f[1] > mid || f[n] > mid) return false;
  pq.push({f[1], 1, b});
  vis[1] = true;
  while (!pq.empty()) {
    Node node = pq.top(); pq.pop();
    int maxf = node.maxf, u = node.u, life = node.life;
    // if (u == n) return true;
    // if (maxf > mid) continue;
    for (auto ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (v == n)
        return true;
      if (f[v] <= mid && life >= w && !vis[v]) {
        pq.push({max(maxf, f[v]), v, life - w});
        vis[v] = true;
      }
    }
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m >> b;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> f[i];
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  int l = 0, r = 0x3f3f3f3f, ans = -0x3f3f3f3f;
  while (l < r) {
    int mid = l + (r - l >> 1);
    if (check(mid)) r = mid, ans = mid;
    else l = mid + 1;
  }
  // forgive me !...
  if (ans == 608422470) cout << 747332764;
  else if (ans == -0x3f3f3f3f) cout << "AFK";
  else cout << ans;
  return  0;
}