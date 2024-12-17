#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> gc(n + 1), g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    gc[a[i]].push_back(i); // 仅记录颜色间边的图
  }
  std::vector<int> inc(n + 1), vis(n + 1), in(n + 1), nxt(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y); // 记录点之间边的图
    if (a[x] != a[y]) { // inc仅存不同颜色间的度数
      inc[a[y]]++;
    }
    in[y]++;
  }
  std::queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!inc[i]) { // 当前颜色可以放，不存在任何其他颜色指向当前颜色，也必须放
      q.push(i);
      vis[i] = 1;
    }
  }

  std::vector<int> ans;
  auto topo = [&](int u) {
    // 对某个颜色内部进行拓扑排序，同时处理当前颜色向其他颜色延申导致的其他颜色度数减少的情况
    std::queue<int> que;
    for (int i : gc[u]) { // 颜色u的没有入度的所有点
      if (!in[i]) {
        que.push(i);
      }
    }
    while (!que.empty()) {
      int v = que.front(); que.pop();
      ans.push_back(v);
      for (int vv : g[v]) {
        if (a[vv] != a[v]) { // 处理不同颜色
          --inc[a[vv]];
          if (!inc[a[vv]]) { // 动态处理当前可以放入的颜色
            q.push(a[vv]);
            vis[a[vv]] = 1;
          }
        }
        if (!--in[vv] && a[vv] == a[v]) { // 拓扑排序内只考虑当前颜色，因为必须要一个颜色一个颜色来
          que.push(vv);
        }
      }
    }
  };

  while (!q.empty()) {
    int u = q.front(); q.pop();
    topo(u);
    for (auto c : gc[u]) {
      if (!inc[c] && !vis[c]) { // 没有度数的颜色
        q.push(c);
      }
    }
  }
  if (ans.size() != n) {
    std::cout << -1 << '\n';
    return;
  }
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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