// date: 2024-05-12 13:46:17
// tag: 2-sat
// 测试数据过少
// 1971H

#include <bits/stdc++.h>
#define int long long
#define N 500
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(4, vector<int>(n + 1));
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> g(n * 2);
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= 3; i++) {
      int x = a[i][j] * 2 - 1;
      if (a[i][j] < 0) x = (-a[i][j] * 2 - 1) ^ 1;
      for (int k = 1; k <= 3; k++) {
        if (k != i) {
          int y = a[k][j] * 2 - 1;
          if (a[k][j] < 0) y = (-a[k][j] * 2 - 1) ^ 1;
          g[x].push_back(y ^ 1);
        }
      }
    }
  }
  // for (int i = 0; i < n * 2; i++) {
  //   cout << i << '\n';
  //   for (auto v : g[i]) {
  //     cout << v << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';

  vector<int> dfn(n * 2), scc(n * 2), low(n * 2);
  bitset<(N + 5) << 1> ins;
  int scc_cnt = 0, dfncnt = 0;
  stack<int> s;
  auto tarjan = [&](auto self, int u) -> void {
    low[u] = dfn[u] = ++dfncnt;
    s.push(u);
    ins[u] = true;
    for (int v : g[u]) {
      if (!dfn[v]) {
        self(self, v);
        low[u] = min(low[u], low[v]);
      } else if (ins[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (low[u] == dfn[u]) {
      ++scc_cnt;
      while (true) {
        int x = s.top(); s.pop();
        scc[x] = scc_cnt;
        ins[x] = false;
        if (x == u) break;
      }
    }
  };
  for (int i = 0; i < n * 2; i++) {
    if (!dfn[i]) {
      tarjan(tarjan, i);
    }
  }

  for (int i = 0; i < n * 2; i++) {
    if (scc[i] == scc[i ^ 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";

  for (int i = 0; i < n * 2; i += 2) {
    cerr << (scc[i ^ 1] < scc[i] ? -1 : 1) << ' ';
  }
  cerr << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}