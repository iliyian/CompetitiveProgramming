#include <bits/stdc++.h>
#define int long long

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::bitset<16384>> c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }
  std::vector<std::vector<int>> g(n);
  HLD hld(n);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    hld.addEdge(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> leaf, dep(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    if (g[u].size() == 2 && u != 0) {
      leaf.push_back(u);
    }
    for (int v : g[u]) {
      if (v != p) {
        dep[v] = dep[u] + 1;
        c[v] = c[u];
        c[v].set(a[v]);
        self(self, v, u);
      }
    }
  };
  c[0].set(a[0]);
  dfs(dfs, 0, -1);
  hld.work();
  int ans = 0;
  std::ranges::sort(leaf, [&](auto x, auto y) {
    return dep[x] > dep[y];
  });
  int k = std::min<int>(500, leaf.size());
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      int x = leaf[i], y = leaf[j];
      int z = hld.lca(x, y);
      ans = std::max<int>(ans, ((c[x] ^ c[z]) | (c[y] ^ c[z])).set(a[z]).count());
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}