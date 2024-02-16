#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }
  vector<int> siz(n + 1), son(n + 1);
  auto dfs1 = [&](auto self, int x) -> void {
    siz[x] = 1;
    for (int y : adj[x]) {
      self(self, y);
      siz[x] += siz[y];
      if (siz[y] > siz[son[x]])
        son[x] = y;
    }
  };
  dfs1(dfs1, 1);
  auto dfs2 = [&](auto self, int x) -> int {
    if (siz[son[x]] * 2 > siz[x] - 1) {
      int v = self(self, son[x]);
      return v + min((siz[x] - 1 - v * 2) / 2, siz[x] - 1 - siz[son[x]]);
    } else {
      return (siz[x] - 1) / 2;
    }
  };
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