#include <bits/stdc++.h>
#define int long long

/**   强连通分量缩点（SCC）
 *    2023-06-18: https://codeforces.com/contest/1835/submission/210147209
**/
struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  SCC scc(n);
  std::vector<std::vector<int>> g(n);
  for (int i = 1; i <= m; i++) {
    int a, b;
    std::cin >> a >> b;
    a = (a % n + n) % n;
    scc.addEdge(a, (a + b % n + n) % n);
    g[a].push_back(b);
  }
  auto bel = scc.work();
  std::vector<int> s(scc.cnt), in(scc.cnt);
  std::vector<std::vector<int>> h(scc.cnt);
  for (int u = 0; u < n; u++) {
    for (int w : g[u]) {
      int v = (u + w % n + n) % n;
      if (bel[u] != bel[v]) {
        h[bel[v]].push_back(bel[u]);
      }
    }
  }
  std::vector<int> vis(n), height(n);
  bool f = true;
  auto dfs = [&](this auto &&self, int u) -> void {
    for (int w : g[u]) {
      int v = (u + w % n + n) % n;
      if (bel[v] == bel[u] && !vis[v]) {
        vis[v] = 1;
        height[v] = height[u] + w;
        self(v);
      }
    }
  };
  auto dfs3 = [&](this auto &&self, int u) -> void {
    for (int w : g[u]) {
      int v = (u + w % n + n) % n;
      if (bel[v] == bel[u]) {
        if (height[v] != height[u] + w) {
          f = true;
        }
        if (vis[v] != 2) {
          vis[v] = 2;
          self(v);
        }
      }
    }
  };
  std::vector<int> ans(scc.cnt);
  for (int u = 0; u < n; u++) {
    if (!vis[u]) {
      dfs(u);
      f = false;
      dfs3(u);
      if (f) {
        ans[bel[u]] = 1;
      }
    }
  }
  auto dfs2 = [&](this auto &&self, int u) -> void {
    for (int v : h[u]) {
      if (ans[v]) continue;
      ans[v] = 1;
      self(v);
    }
  };
  for (int i = 0; i < scc.cnt; i++) {
    if (ans[i]) {
      dfs2(i);
    }
  }
  while (q--) {
    int x;
    std::cin >> x;
    x = (x % n + n) % n;
    std::cout << (ans[bel[x]] == 1 ? "Yes" : "No") << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}