// date: 2024-03-13 17:24:21
// tag: wa,re#01: 没有考虑数字可能不止一位，n和m搞反了，tarjan模板的dfn和low写反，else if (ins[v])写成else
// re#02: 没有考虑数字可能不止一位，tarjan模板错了
// wa#03: tarjan模板错了

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n * 2);
  auto change = [](const string &str) {
    return (stoi(str.substr(1, str.size() - 1)) - 1) * 2
      + (str.front() == 'm');
  };
  for (int i = 1; i <= m; i++) {
    string a, b;
    cin >> a >> b;
    int x = change(a), y = change(b);
    g[x ^ 1].push_back(y);
    g[y ^ 1].push_back(x);
  }
  vector<int> dfn(n * 2), low(n * 2), scc(n * 2);
  vector<bool> ins(n * 2);
  int cnt = 0, scc_cnt = 0;
  stack<int> s;
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
    if (dfn[u] == low[u]) {
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
  for (int i = 0; i < n * 2; i += 2) {
    if (scc[i] == scc[i ^ 1]) {
      cout << "BAD" << '\n';
      return;
    }
  }
  cout << "GOOD" << '\n';
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