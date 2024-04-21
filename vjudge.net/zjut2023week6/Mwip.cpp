#include <bits/stdc++.h>
#define N 100005
using namespace std;

struct Edge {
  int v, w;
};

bitset<N> is;

vector<vector<Edge>> g;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("M.in", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    is[x] = true;
  }
  int ans = 0x3f3f3f3f;
  for (int u = 1; u <= n; u++) {
    if (!is[u]) continue;
    for (auto [v, w] : g[u]) {
      if (!is[v]) ans = min(ans, w);
    }
  }
  cout << (ans == 0x3f3f3f3f ? -1 : ans);
}