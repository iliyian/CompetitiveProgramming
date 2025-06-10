// date: 2025-04-13 12:32:01
// tag: 只能说相当套路的一题二分图匹配+二分

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int inf = LLONG_MAX / 2;
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
        for (int &i = cur[u]; i < g[u].size(); ++i) {
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
  std::vector<int> sx(n + 1), sy(n + 1), gx(n + 1), gy(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> sx[i] >> sy[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> gx[i] >> gy[i];
  }
  std::vector<std::pair<double, std::pair<int, int>>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      v.push_back({std::hypot(sx[i] - gx[j], sy[i] - gy[j]), {i, j}});
    }
  }
  std::sort(v.begin(), v.end());
  auto check = [&](int mid) -> bool {
    MaxFlow<int> f(n * 2 + 2);
    int s = 0, t = n * 2 + 1;
    for (int i = 0; i <= mid; i++) {
      auto [w, xy] = v[i];
      auto [x, y] = xy;
      f.addEdge(x, y + n, 1);
    }
    for (int i = 1; i <= n; i++) {
      f.addEdge(s, i, 1);
      f.addEdge(i + n, t, 1);
    }
    return f.flow(s, t) == n;
  };
  int l = 0, r = v.size() - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << std::fixed << std::setprecision(30) << v[ans].first << '\n';
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