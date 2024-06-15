// date: 2024-06-13 22:05:57
// tag: 贪心，构造，图论

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> edges;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    edges.push_back({x, y});
  }
  vector<int> pa(n + 1);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    pa[x] = y;
  };
  vector<int> ans(edges.size());
  int cur = 0;
  bitset<2000> vis;
  for (int c = 1;; c++) {
    iota(pa.begin() + 1, pa.end(), 1);
    for (; cur < edges.size(); cur++) {
      if (vis[cur]) continue;
      auto [x, y] = edges[cur];
      x = find(find, x), y = find(find, y);

      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (find(find, i) == i) {
          cnt++;
        }
      }

      if (cnt == 2 && x != y) {
        for (int i = 0; i < edges.size(); i++) {
          if (!vis[i] && find(find, edges[i].first) == find(find, edges[i].second)) {
            vis[i] = true;
            ans[i] = c;
          }
        }

        break;
      }
      merge(x, y);
      ans[cur] = c;
      vis[cur] = true;
    }
    if (cur == edges.size()) {
      cout << c << '\n';
      break;
    }
  }
  for (auto c : ans) {
    cout << c << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}