// date: 2024-03-10 21:25:11
// tag: 最小割，最大权闭合子图

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;

struct Edge {
  int v, cap, id;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int m, n;
  cin >> m >> n;
  vector<vector<Edge>> g(n + m + 2);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  int s = 0, t = n + m + 1, sumv = 0;
  cin.get();
  for (int i = 1; i <= m; i++) {
    string str;
    getline(cin, str);
    int pre = 0, p;
    while ((p = str.find(' ', pre)) != string::npos) {
      int x = stoi(str.substr(pre, p));
      if (pre == 0) {
        add(s, i, x);
        sumv += x;
      } else {
        add(i, x + m, inf);
      }
      pre = p + 1;
    }
    int x = stoi(str.substr(pre, str.size() - pre));
    add(i, x + m, inf);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(i + m, t, x);
  }
  vector<int> d(n + m + 2), cur(n + m + 2), dep(n + m + 2);
  auto bfs = [&]() {
    fill(cur.begin(), cur.end(), 0);
    fill(dep.begin(), dep.end(), 0);
    dep[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto &[v, cap, id] : g[u]) {
        if (!dep[v] && cap) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[t];
  };
  auto dfs = [&](auto self, int u, int lim) -> int {
    if (u == t) {
      return lim;
    }
    for (int i = cur[u]; i < g[u].size(); i++) {
      cur[u] = i;
      auto &[v, cap, id] = g[u][i];
      if (dep[v] == dep[u] + 1 && cap) {
        int t = self(self, v, min(cap, lim));
        if (t) {
          cap -= t;
          g[v][id].cap += t;
          return t;
        } else {
          dep[v] = 0;
        }
      }
    }
    return 0;
  };
  int res = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      res += r;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (dep[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  for (int i = m + 1; i <= m + n; i++) {
    if (dep[i]) {
      cout << i - m << ' ';
    }
  }
  cout << '\n';
  cout << sumv - res << '\n';

  return 0;
}