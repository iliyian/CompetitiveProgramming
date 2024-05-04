// date: 2024-05-03 14:46:36
// tag: 数学，置换环

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  int l = 1, r = n;
  int f = 0;
  bitset<N + 5> vis;
  vector<int> siz(n + 1);
  auto dfs1 = [&](auto self, int u) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (!siz[v]) {
        self(self, v);
        siz[u] += siz[v];
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!siz[i]) {
      dfs1(dfs1, i);
    }
  }

  auto dfs = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int v : g[u]) {
      if (!vis[v]) {
        self(self, v);
      }
    }
  };
  vector<int> id(n + 1);
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return siz[x] > siz[y];
  });
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[id[i]]) {
      dfs(dfs, id[i]);
      int a = siz[id[i]] / 2;
      ans += a;
    }
  }
  cout << 2 * ans * (n - ans) << '\n';
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