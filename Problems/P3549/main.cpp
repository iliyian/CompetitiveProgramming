#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  auto add = [](int x, int y, vector<vector<int>> &g) {
    g[x].push_back(y);
    g[y].push_back(x);
  };
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y, g);
  }
  int t = n, s = 1;
  vector<int> prv(n + 1), nxt(n + 1);
  auto dfs1 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        prv[v] = u;
        self(self, v, u);
      }
    }
  };
  dfs1(dfs1, s, 0);

  bitset<N> isd;
  for (int u = t; u; u = prv[u]) {
    isd[u] = true;
    nxt[prv[u]] = u;
  }

  bool f = true;
  auto dfs2 = [&](auto self, int u, int p, int cnt) {
    if (!f) return;
    if (cnt >= 2) {
      f = false;
      return;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, cnt + (!isd[v]));
      }
    }
  };
  dfs2(dfs2, s, 0, 0);
  if (!f) {
    cout << "BRAK\n";
    return 0;
  }

  vector<vector<int>> gg(n + 1);
  for (int u = t; u; u = prv[u]) {
    if (u != s && u != t) {
      vector<int> ch;
      for (int v : g[u]) {
        if (v != prv[u] && v != nxt[u]) {
          ch.push_back(v);
        }
      }
      if (!ch.empty()) {
        add(prv[u], ch.front(), gg);
        add(nxt[u], ch.back(), gg);
        for (int i = 1; i < ch.size(); i++) {
          add(ch[i], ch[i - 1], gg);
        }
      } else {
        add(prv[u], nxt[u], gg);
      }
    }
  }

  auto dfs3 = [&](auto self, int u, int p) {
    cout << u << '\n';
    for (int v : gg[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };

  return 0;
}