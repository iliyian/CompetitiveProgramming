// date: 2024-05-10 13:04:29
// tag: 拓扑排序

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    in[y]++;
  }
  for (int t = 1; t <= n + 1; t++) {
    vector<int> cur;
    for (int u = 1; u <= n; u++) {
      if (a[u] > 0) {
        cur.push_back(u);
      }
    }
    for (auto u : cur) {
      a[u]--;
      for (auto v : g[u]) {
        a[v]++;
      }
    }
    if (cur.empty()) {
      cout << t - 1 << '\n';
      return;
    }
  }

  queue<int> q;
  for (int u = 1; u <= n; u++) {
    if (!in[u]) {
      q.push(u);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   cerr << a[i] << " \n"[i == n];
  // }

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      a[v] += a[u];
      a[v] %= mod;
      if (!--in[v]) {
        q.push(v);
      }
    }
    if (g[u].empty()) {
      cout << (a[u] + n + 1) % mod << '\n';
      break;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   cerr << a[i] << " \n"[i == n];
  // }
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