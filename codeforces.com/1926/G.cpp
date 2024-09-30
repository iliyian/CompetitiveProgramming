#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    adj[x].push_back(i);
  }
  vector<char> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<array<int, 3>> dp(n + 1);
  auto dfs = [&](auto self, int x) -> void {
    dp[x].fill(inf);
    dp[x][a[x] == 'P' ? 1 : (a[x] == 'S' ? 2 : 0)] = 0;
    for (int y : adj[x]) {    
      self(self, y);
      array<int, 3> cur;
      cur.fill(inf);
      for (int u = 0; u < 3; u++) {
        for (int v = 0; v < 3; v++) {
          if ((u | v) != 3) {
            cur[u | v] = min(cur[u | v], dp[x][u] + dp[y][v]);
          }
          cur[u] = min(cur[u], dp[x][u] + dp[y][v] + 1);
        }
      }
      dp[x] = cur;
    }
  };
  dfs(dfs, 1);
  cout << min({dp[1][0], dp[1][1], dp[1][2]}) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}