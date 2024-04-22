// date: 2024-04-22 16:28:38
// tag: 按位贪心，生成树

#include <bits/stdc++.h>
#include <vector>
#define N 200005
#define int long long
using namespace std;

struct Ed {
  int u, v, w;
};

struct Edge {
  int v, w;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Ed> edges;
  vector<vector<Edge>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges.push_back({u, v, w});
  }

  vector<int> pa(n + 1), siz(n + 1);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };

  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
  };

  bitset<N> banned;
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int cnt = 0;
    iota(pa.begin(), pa.end(), 0);
    fill(siz.begin(), siz.end(), 1);
    vector<int> ban;
    for (int j = 0; j < m; j++) {
      if (!banned[j]) {
        auto &[u, v, w] = edges[j];
        if (w >> i & 1 ^ 1) {
          merge(u, v);
        } else {
          ban.push_back(j);
        }
      }
    }
    bool f = false;
    for (int i = 1; i <= n; i++) {
      if (pa[i] == i && siz[i] == n) {
        f = true;
        break;
      }
    }
    if (f) {
      for (auto j : ban) {
        banned[j] = true;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (!banned[i]) {
      ans |= edges[i].w;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}