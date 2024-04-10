// date: 2024-04-08 21:41:22
// tag: 卡double精度

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int y, w, k;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    double k;
    cin >> x >> y >> w >> k;
    g[x].push_back({y, w, signed(k * 10)});
  }

  vector<int> dfn(n + 1), low(n + 1), scc(n + 1);
  vector<bool> ins(n + 1);
  stack<int> s;
  int cnt = 0, scc_cnt = 0;
  auto tarjan = [&](auto self, int x) -> void {
    dfn[x] = low[x] = ++cnt;
    s.push(x);
    ins[x] = true;
    for (auto &[y, w, k] : g[x]) {
      if (!dfn[y]) {
        self(self, y);
        low[x] = min(low[x], low[y]);
      } else if (ins[y]) {
        low[x] = min(low[x], dfn[y]);
      }
    }
    if (dfn[x] == low[x]) {
      ++scc_cnt;
      while (true) {
        int u = s.top(); s.pop();
        ins[u] = false;
        scc[u] = scc_cnt;
        if (u == x) break;
      }
    }
  };
  int S;
  cin >> S;
  tarjan(tarjan, S);

  vector<int> val(scc_cnt + 1);
  vector<vector<Edge>> gg(scc_cnt + 1);

  for (int x = 1; x <= n; x++) {
    for (auto [y, w, k] : g[x]) {
      if (scc[x] == scc[y]) {
        // assert(x != y);
        while (w) {
          val[scc[x]] -= w;
          w = w * k / 10;
          assert(w * k / 10.0 == w * (k / 10.0));
        }
      } else {
        gg[scc[x]].push_back({scc[y], -w, 0});
      }
    }
  }

  queue<int> q;
  vector<int> dis(scc_cnt + 1, INT_MAX);
  vector<bool> vis(scc_cnt + 1);
  dis[scc[S]] = 0, vis[scc[S]] = true;
  int ans = 0;
  q.push(scc[S]);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    vis[x] = false;
    for (auto &[y, w, k] : gg[x]) {
      if (dis[y] > dis[x] + w + val[y]) {
        dis[y] = dis[x] + w + val[y];
        ans = min(ans, dis[y]);
        if (!vis[y]) {
          q.push(y), vis[y] = true;
        }
      }
    }
  }
  cout << - val[scc[S]] - ans << '\n';

  return 0;
}