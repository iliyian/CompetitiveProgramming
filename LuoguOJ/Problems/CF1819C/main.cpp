// date: 2024-04-05 12:02:21
// tag: 树的直径，毛毛虫，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void add(int x, int y, vector<vector<int>> &g) {
  g[x].push_back(y);
  g[y].push_back(x);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y, g);
  }
  int c = 0;
  vector<bool> isd(n + 1);
  vector<int> pa(n + 1), nxt(n + 1), dep(n + 1);
  auto dfs1 = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    if (dep[u] > dep[c]) {
      c = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        pa[v] = u;
        self(self, v, u);
      }
    }
  };
  dfs1(dfs1, 1, 0);
  dep[c] = 0;
  int d = c;
  fill(pa.begin(), pa.end(), 0);
  dfs1(dfs1, c, 0);
  for (int u = c; u; u = pa[u]) {
    isd[u] = true;
    nxt[pa[u]] = u;
  }

  bool f = true;
  auto dfs2 = [&](auto self, int u, int p, int cnt) {
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
  dfs2(dfs2, 1, 0, 0);
  if (!f) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";

  vector<vector<int>> gg(n + 1);

  for (int u = c; u; u = pa[u]) {
    if (u != c && u != d) {
      vector<int> ch;
      for (int v : g[u]) {
        if (v != nxt[u] && v != pa[u]) {
          ch.push_back(v);
        }
      }
      if (!ch.empty()) {
        add(pa[u], ch.front(), gg);
        add(nxt[u], ch.back(), gg);
        for (int i = 1; i < ch.size(); i++) {
          add(ch[i - 1], ch[i], gg);
        }
      } else {
        add(pa[u], nxt[u], gg);
      }
    }
  }
  add(c, pa[c], gg);
  vector<bool> vis(n + 1);
  vector<int> ans;
  auto dfs3 = [&](auto self, int u, int p) -> void {
    ans.push_back(u);
    for (int v : gg[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs3(dfs3, d, 0);
  for (auto i : ans) {
    cout << i << ' ';
  }

  return 0;
}