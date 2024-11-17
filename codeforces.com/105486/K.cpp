#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
struct MinCostFlow {
  struct _Edge {
    int to;
    T cap;
    T cost;
    _Edge(int to_, T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}
  };
  int n;
  vector<_Edge> e;
  vector<vector<int>> g;
  vector<T> h, dis;
  vector<int> pre;
  bool dijkstra(int s, int t) {
    dis.assign(n, numeric_limits<T>::max());
    pre.assign(n, -1);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
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
    return dis[t] != numeric_limits<T>::max();
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
  pair<T, T> flow(int s, int t) {
    T flow = 0;
    T cost = 0;
    h.assign(n, 0);
    while (dijkstra(s, t)) {
      for (int i = 0; i < n; i++) {
        h[i] += dis[i];
      }
      T aug = numeric_limits<T>::max();
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        aug = min(aug, e[pre[i]].cap);
      }
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap -= aug;
        e[pre[i] ^ 1].cap += aug;
      }
      flow += aug;
      cost += aug * h[t];
    }
    return make_pair(flow, cost);
  }
  struct Edge {
    int from;
    int to;
    T cap;
    T cost;
    T flow;
  };
  vector<Edge> edges() {
    vector<Edge> a;
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
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> fac;
  std::set<int> se;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    se.insert(a[i]);
  }
  if (!se.count(1)) {
    fac.push_back(1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        if (!se.count(j)) {
          fac.push_back(j);
        }
        if (!se.count(a[i] / j)) {
          fac.push_back(a[i] / j);
        }
      }
    }
  }
  std::sort(fac.begin(), fac.end());
  fac.erase(std::unique(fac.begin(), fac.end()), fac.end());
  int m = fac.size();
  int s = 0, t = n + m + 1;
  MinCostFlow<int> f(t + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m && fac[j] < a[i]; j++) {
      if (a[i] % fac[j] == 0) {
        int cost = 0, t = a[i] / fac[j];
        for (int k = 2; k * k <= t; k++) {
          while (t % k == 0) {
            t /= k;
            cost++;
          }
        }
        if (t > 1) cost++;
        f.addEdge(i, n + j + 1, 1, -cost);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    f.addEdge(s, i, 1, 0);
  }
  for (int j = 0; j < m; j++) {
    f.addEdge(n + j + 1, t, 1, 0);
  }
  std::cout << -f.flow(s, t).second << '\n';
  auto edges = f.edges();
  // for (int i = 0; i < m; i++) {
  //   std::cout << fac[i] << " \n"[i == m - 1];
  // }
  int sum = 0;
  for (auto [from, to, cap, cost, flow] : edges) {
    if (from == s || to == t || !flow) continue;
    std::cout << a[from] << ' ' << fac[to - 1 - n] << ' ' << cost << ' ' << flow << '\n';
    sum += -cost;
  }
  std::cout << sum << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};