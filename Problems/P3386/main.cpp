// date: 2024-03-07 21:31:24
// tag: 二分图最大匹配，匈牙利算法

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, e;
  cin >> n >> m >> e;
  vector<vector<int>> adj(max(n, m) + 1);
  vector<int> mch(max(n, m) + 1), vis(max(n, m) + 1);
  for (int i = 1; i <= e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  auto dfs = [&](auto self, int u, int tag) -> bool {
    if (vis[u] == tag) return false;
    vis[u] = tag;
    for (int v : adj[u]) {
      if (!mch[v] || self(self, mch[v], tag)) {
        mch[v] = u;
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dfs(dfs, i, i)) {
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}