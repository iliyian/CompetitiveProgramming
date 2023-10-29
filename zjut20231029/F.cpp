#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;

int a[200001], k[200001];

struct Node {
  int u;
  bool operator < (const Node &b) const {
    // if (k[u] == k[b.u]) return a[u] < a[b.u];
    return k[u] > k[b.u];
    // return a[u] < a[b.u];
  }
};

signed main() {
  freopen("F.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    k[u] += a[v], k[v] += a[u];
  }
  priority_queue<Node> q;
  for (int i = 1; i <= n; i++)
    q.push({i});
  int ans = -0x3f3f3f3f;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    ans = max(ans, k[u]);
    for (int v : g[u])
      k[v] -= a[u];
  }
  cout << ans;
  return 0;
}