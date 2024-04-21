// date: 2024-03-28 11:39:47
// tag: 二分，树形dp
// wa#01: 应该是siz和dp分开导致的siz更新不及时导致的

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }

  auto check = [&](int mid) -> bool {
    int rek = k, tot = n;
    vector<int> siz(n + 1);
    auto dp = [&](auto self, int u, int p) -> void {
      siz[u] = 1;
      for (int v : g[u]) {
        if (v != p) {
          self(self, v, u);
          siz[u] += siz[v];
        }
      }
      if (siz[u] >= mid && tot - siz[u] >= mid && rek > 0) {
        rek--;
        tot -= siz[u];
        siz[u] = 0;
      }
    };
    dp(dp, 1, 0);
    return !rek;
  };
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  };
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}