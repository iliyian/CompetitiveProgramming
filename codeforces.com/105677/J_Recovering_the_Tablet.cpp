// date: 2025-03-28 16:36:41
// tag: 神奇最大流+费用流，拆边，拆点，最小代价，可行性

#include <bits/stdc++.h>
#define int long long

constexpr int inf = INT_MAX;
template<class T>
struct MinCostFlow {
    struct _Edge {
        int to;
        T cap;
        T cost;
        _Edge(int to_, T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}
    };
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<T> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<T>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            T d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] != d) {
                continue;
            }
            for (int i : g[u]) {
                int v = e[i].to;
                T cap = e[i].cap;
                T cost = e[i].cost;
                if (cap > 0 && dis[v] > d + h[u] - h[v] + cost) {
                    dis[v] = d + h[u] - h[v] + cost;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<T>::max();
    }
    MinCostFlow() {}
    MinCostFlow(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        e.clear();
        g.assign(n, {});
    }
    void addEdge(int u, int v, T cap, T cost) {
        g[u].push_back(e.size());
        e.emplace_back(v, cap, cost);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -cost);
    }
    std::pair<T, T> flow(int s, int t) {
        T flow = 0;
        T cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) {
                h[i] += dis[i];
            }
            T aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                aug = std::min(aug, e[pre[i]].cap);
            }
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return std::make_pair(flow, cost);
    }
    struct Edge {
        int from;
        int to;
        T cap;
        T cost;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.cost = e[i].cost;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

void solve() {
  int m, n, k;
  std::cin >> m >> n >> k;
  std::vector<std::string> a(m + 1);
  int sum = 0;
  int s = 0, t = k + m * n * 2 + 1;
  MinCostFlow<long long> g(k + m * n * 2 + 2);
  auto l = [&](int x, int y) {
    return ((x - 1) * n + y) * 2 - 1;
  };
  auto r = [&](int x, int y) {
    return ((x - 1) * n + y) * 2;
  };
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != '0') {
        sum += a[i][j] - '1';
        g.addEdge(l(i, j), r(i, j), a[i][j] - '1', -1);
        g.addEdge(l(i, j), r(i, j), 8 - (a[i][j] - '1'), 1);
      }
    }
  }
  int s1 = 0, t1 = 0;
  for (int i = 1; i <= k; i++) {
    char op;
    int x, y, v;
    std::cin >> op >> x >> y >> v;
    int cnt = -1, xx = x, yy = y;
    do {
      cnt++;
      (op == 'V' ? xx : yy)++;
    } while (xx <= m && yy <= n && a[xx][yy] != '0');
    (op == 'V' ? x : y)++;
    while (x <= m && y <= n && a[x][y] != '0') {
      if (op == 'V') {
        g.addEdge(i + m * n * 2, l(x, y), inf, 0);
      } else {
        g.addEdge(r(x, y), i + m * n * 2, inf, 0);
      }
      (op == 'V' ? x : y)++;
    }
    if (op == 'V') {
      g.addEdge(s, i + m * n * 2, v - cnt, 0);
      s1 += v - cnt;
    } else {
      g.addEdge(i + m * n * 2, t, v - cnt, 0);
      t1 += v - cnt;
    }
  }
  auto [flow, cost] = g.flow(s, t);
  if (s1 != t1) {
    std::cout << "IMPOSSIBLE\n";
    return;
  }
  std::cout << cost + sum << '\n';
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