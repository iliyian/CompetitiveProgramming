// date: 2025-07-14 16:11:46
// tag: 开心，第一次完全自己做出来的网络流。虽然参考了一些资料，但是都是板子。如果A的实现可以带来B，不妨转换成有B必须要有A的最大权闭合子图。如果B是分层的，不妨把贡献也转换为有更高层的必须要有更低层的，然后逐层拆开即可。

#include <bits/stdc++.h>
#define int long long

/**   最大流（MaxFlow 新版）
 *    2023-07-21: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62915815
**/
constexpr int inf = 1E9;
template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };
    
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    
    MaxFlow() {}
    MaxFlow(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < (int)(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
    
    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    
    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> w(n + 1), v(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i];
  }
  sum += v[n] * n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  MaxFlow<int> f(n * (n + 1) + 2);
  int s = 0, t = n * (n + 1) + 1;
  for (int i = 1; i <= n; i++) {
    f.addEdge(n * n + i, t, w[i]);
  }
  auto dfs = [&](auto self, int u, int p, int d, int rt) -> void {
    f.addEdge((u - 1) * n + d + 1, n * n + rt, inf);
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, d + 1, rt);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f.addEdge(s, (i - 1) * n + j, v[j] - v[j - 1]);
      if (j >= 2) {
        f.addEdge((i - 1) * n + j, (i - 1) * n + j - 1, inf);
      }
    }
    dfs(dfs, i, 0, 0, i);
  }
  // std::cerr << sum << '\n';
  // for (auto i : f.minCut()) {
  //   std::cout << i << '\n';
  // }
  // for (auto &[u, v, cap, flow] : f.edges()) {
  //   std::cerr << u << ' ' << v << ' ' << cap << ' ' << flow << '\n';
  // }
  std::cout << sum - f.flow(s, t) << '\n';
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