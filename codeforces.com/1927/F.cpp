// date: 2024/02/08 12:56:26
// tag: lambda函数也可以递归
// tmd，因为这个和1927B，都tmd是2e5，我写成1e5两个都t了好久好久啊艹艹艹

#include <bits/stdc++.h>
#define N 200005
using namespace std;

struct Edge {
  int u, v, w;
};

struct Ed {
  int v, w;
};

int pa[N];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge> vec;
  vector<vector<int>> g;
  g.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    vec.push_back({u, v, w});
  }
  sort(vec.begin(), vec.end(), [&](const Edge &x, const Edge &y) {
    return x.w > y.w;
  });
  int U = -1, V = -1, mi = 0x3f3f3f3f;
  iota(pa + 1, pa + 1 + n, 1);
  
  for (auto [u, v, w] : vec) {
    int pu = find(u), pv = find(v);
    if (pu != pv) {
      g[u].push_back(v);
      g[v].push_back(u);
      pa[pu] = pv;
    } else {
      mi = w;
      U = u, V = v;
    }
  }
  vector<int> ans;
  auto dfs = [&](auto self, int u, int p) {
    if (u == V) {
      ans.push_back(u);
      return true;
    }
    for (int v : g[u]) {
      if (v == p) continue;
      if (self(self, v, u)) {
        ans.push_back(u);
        return true;
      }
    }
    return false;
  };
  dfs(dfs, U, -1);
  cout << mi << ' ' << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}