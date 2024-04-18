// date: 2024-04-16 15:46:05
// tag: 强连通分量，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  iota(id.begin(), id.end(), 0);
  vector<vector<int>> g(n + 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] > a[y];
  });
  for (int i = 1; i <= n - 1; i++) {
    g[id[i]].push_back(id[i + 1]);
  }

  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return b[x] > b[y];
  });
  for (int i = 1; i <= n - 1; i++) {
    g[id[i]].push_back(id[i + 1]);
  }

  vector<int> dfn(n + 1), low(n + 1), scc(n + 1);
  bitset<100001> ins;
  stack<int> s;
  int cnt = 0, scc_cnt = 0;
  auto tarjan = [&](auto self, int u) -> void {
    dfn[u] = low[u] = ++cnt;
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
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(tarjan, i);
    }
  }
  vector<int> in(scc_cnt + 1);
  for (int u = 1; u <= n; u++) {
    for (int v : g[u]) {
      if (scc[v] != scc[u]) {
        in[scc[v]]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (!in[scc[i]]);
  }
  cout << '\n';
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