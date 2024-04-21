#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  vector<bool> vis(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
  }
  sort(edges.begin(), edges.end());
  m = unique(edges.begin(), edges.end()) - edges.begin();

  // if (m > (n - 1) / 2) {
  //   cout << "NO\n";
  //   return;
  // }

  vector<unordered_set<int>> g(n + 1);
  vector<tuple<int, int>> ans;
  for (int i = 0; i < m; i++) {
    auto &[x, y] = edges[i];
    g[x].insert(y);
    g[y].insert(x);
  }
  auto isold = [&](int x, int y) {
    return g[x].find(y) != g[x].end();
  };
  
  vector<int> pa(n + 1);
  iota(pa.begin() + 1, pa.end(), 1);

  auto find = [&pa](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };

  set<int> rest;
  for (int i = 1; i <= n; i++) {
    rest.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    vector<int> del;
    for (auto &j : rest) {
      if (!isold(i, j) && find(find, i) != find(find, j)) {
        pa[find(find, i)] = find(find, j);
        del.push_back(j);
        ans.push_back({i, j});
      }
    }
    if (ans.size() == n - 1) {
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
      }
      return;
    }
    for (auto j : del) {
      rest.erase(j);
    }
  }

  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("M.in", "r", stdin);
  freopen("M.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}