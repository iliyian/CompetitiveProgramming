// date: 2024/02/14 20:20:56
// tag: 往往使用“拓扑排序”判断矛盾
// 画图是很好的理解方式

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k + 1, vector<int>(n + 1));
  vector<vector<int>> adj(n + 1);
  vector<int> in(n + 1);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
    for (int j = 2; j < n; j++) {
      adj[a[i][j]].push_back(a[i][j + 1]);
      in[a[i][j + 1]]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  vector<int> L;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    L.push_back(u);
    for (int v : adj[u]) {
      if (!--in[v]) { // 重边不影响
        q.push(v);
      }
    }
  }
  // 画图以理解
  cout << (L.size() == n ? "YES" : "NO") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}