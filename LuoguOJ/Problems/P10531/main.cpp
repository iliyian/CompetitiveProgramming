// date: 2024-05-23 13:34:04
// tag: 树上启发式合并，贪心，并查集

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> col(n + 1);
  vector<set<int>> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> col[i];
    s[i].insert(col[i]);
  }
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> pa(n + 1);
  iota(pa.begin(), pa.end(), 0);
  int ans = 0;
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (s[x].size() > s[y].size()) swap(x, y);
    pa[x] = y;
    s[y].insert(s[x].begin(), s[x].end());
  };
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (s[find(find, v)].size() >= k) {
          ans++;
        } else {
          merge(u, v);
        }
      }
    }
  };
  dfs(dfs, 1, 0);
  ans += s[find(find, 1)].size() >= k;
  cout << ans << '\n';

  return 0;
}