// date: 2024-04-07 17:15:11
// tag: 构造，树形dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> h(n + 1);
  int rt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    if (h[i] > h[rt]) {
      rt = i;
    }
  }
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  auto dfs = [&](auto self, int u, int p) -> int {
    int mx1 = 0, mx2 = 0;
    for (int v : g[u]) {
      if (v != p) {
        int mx = self(self, v, u);
        if (mx > mx1) {
          mx2 = mx1;
          mx1 = mx;
        } else if (mx > mx2) {
          mx2 = mx;
        }
      }
    }
    if (h[u] > mx1) {
      ans += h[u] - mx1;
      mx1 = h[u];
    }
    if (p == 0) {
      ans += max(0ll, h[u] - mx1) + max(0ll, h[u] - mx2);
    }
    return mx1;
  };
  dfs(dfs, rt, 0);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  solve();

  return 0;
}