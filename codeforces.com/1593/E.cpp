// date: 2024-04-14 11:35:05
// tag: 拓扑排序

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    in[u]++, in[v]++;
  }
  queue<int> q;
  vector<int> rnk(n + 1);;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 1) {
      q.push(i);
      rnk[i] = 1;
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (!rnk[v]) {
        if (--in[v] == 1){
          q.push(v);
          rnk[v] = rnk[u] + 1;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (rnk[i] > k) {
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}