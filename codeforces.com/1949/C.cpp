// date: 2024-03-27 20:50:59
// tag: 堆优化bfs，暴力，模拟

#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

int a[200005];
bitset<N> vis;

struct Node {
  int u;
  bool operator < (const Node &b) const {
    return a[u] > a[b.u];
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1, 0);
  fill(a + 1, a + 1 + n, 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    in[u]++, in[v]++;
  }
  priority_queue<Node> q;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 1) {
      q.push({i});
      vis[i] = true;
    }
  }
  while (!q.empty()) {
    auto [u] = q.top(); q.pop();
    for (int v : g[u]) {
      if (vis[v]) continue;
      if (a[v] < a[u]) {
        cout << "NO\n";
        return 0;
      }
      a[v] += a[u];
      a[u] = 0;
      if (--in[v] == 1) {
        q.push({v});
        vis[v] = true;
      }
      break;
    }
  }
  cout << "YES\n";

  return 0;
}