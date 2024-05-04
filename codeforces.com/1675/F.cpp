// date: 2024-05-02 19:42:20
// tag: 树，贪心

#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

void solve() {
  int n, k, s, t;
  cin >> n >> k >> s >> t;
  bitset<N + 1> isK;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    isK[x] = true;
  }
  isK[t] = true;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  vector<int> dis(n + 1);
  auto dfs = [&](auto self, int u, int p) -> int {
    bool f = false;
    dis[u] = dis[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        bool t = self(self, v, u);
        if (t) {
          ans += 2;
        }
        f |= t;
      }
    }
    return isK[u] | f;
  };
  dfs(dfs, s, 0);
  ans -= dis[t] - dis[s];
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}