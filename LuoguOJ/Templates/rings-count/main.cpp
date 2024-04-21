#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;
int f[1 << 19][20];

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) f[1 << i - 1][i] = 1;
  for (int S = 0; S < (1 << n); S++) {
    for (int u = 1; u <= n; u++) {
      if (!(S & (1 << u - 1))) continue;
      for (int v : g[u]) {
        int low = S & -S;
        if (low > (1 << v - 1)) continue;
        if (low == (1 << v - 1))
          ans += f[S][u];
        else if (!(S & (1 << v - 1)))
          f[S | (1 << v - 1)][v] += f[S][u];
      }
    }
  }
  cout << (ans - m) / 2 << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}