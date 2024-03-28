#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    adj[x].push_back(i);
  }
  vector<int> dep(n + 1);
  map<int, int> cnt;
  int maxdep = 0, maxleaf = 0, leaf = 0;
  auto dfs1 = [&](auto self, int x, int p) -> void {
    dep[x] = dep[p] + 1;
    maxdep = max(maxdep, dep[x]);
    for (int y : adj[x]) {
      if (y == p) {
        continue;
      }
      self(self, y, x);
    }
    if (!adj[x].empty()) {
      cnt[dep[x] + 1]++;
    }
  };
  auto dfs2 = [&](auto self, int x, int p) -> void {
    for (int y : adj[x]) {
      if (y == p) {
        continue;
      }
      self(self, y, x);
    }
    for (int y : adj[x]) {
      if (dep[y] == maxdep) {
        leaf++;
      }
    }
    maxleaf = max(maxleaf, leaf);
    leaf = 0;
  };
  dfs1(dfs1, 1, 0);
  dfs2(dfs2, 1, 0);
  // cerr << maxdep << ' ' << maxleaf << '\n';
  if (maxdep == 1) {
    cout << 1 << '\n';
    return;
  }
  int ans = 1;
  for (auto [k, v] : cnt) {
    ans ^= (v == 1);
  }
  cout << ans << '\n';
  // cout << ((maxdep % 2) ^ (maxleaf == 1) ? 0 : 1) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}