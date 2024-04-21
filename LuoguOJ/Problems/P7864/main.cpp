// date: 2024-03-16 19:32:25
// tag: 博弈论

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  vector<int> siz(n + 1), dep(n + 1);
  bool f = false;
  auto dfs = [&](auto self, int u, int p, int gr) -> void {
    dep[u] = dep[p] + 1;
    if (g[u].size() >= 2) {
      gr = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, gr);
      }
    }
    if (g[u].empty()) {
      if ((dep[gr] - dep[u]) % 2) {
        f = true;
      }
    }
  };
  dfs(dfs, 1, 0, 0);
  cout << signed(f) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}