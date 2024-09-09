#include <bits/stdc++.h>
using namespace std;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dep(n + 1), vis(n + 1), vec, pa(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    if (vis[u]) return;
    vis[u] = true;
    dep[u] = dep[p] + 1;
    pa[u] = p;
    vec.push_back(u);
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (dep[u] - dep[v] < k && dep[u] - dep[v] > 0) { // 后向边
          std::cout << 2 << '\n';
          std::cout << dep[u] - dep[v] + 1 << '\n';
          while (vec.back() != v) {
            std::cout << vec.back() << ' ';
            vec.pop_back();
          }
          std::cout << v << '\n';
          exit(0);
        }
      }
    }
    vec.pop_back();
  };
  dfs(dfs, 1, 0);
  if (m == n - 1) {
    int cnt1 = std::count_if(dep.begin() + 1, dep.end(), [](const int &x) {
      return x & 1;
    });
    std::cout << 1 << '\n';
    // std::cout << (cnt1 >= (k + 1) / 2 ? cnt1 : n - cnt1) << '\n';
    int cnt = 0;
    for (int i = 1; i <= n && cnt < (k + 1) / 2; i++) {
      if ((dep[i] & 1) == (cnt1 >= (k + 1) / 2)) {
        std::cout << i << ' ';
        cnt++;
      }
    }
    std::cout << '\n';
    return 0;
  }
  
  std::fill(vis.begin(), vis.end(), 0);
  auto dfs2 = [&](auto self, int u, int p) -> void {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (dep[u] - dep[v] >= k - 1) { // 后向边
          std::cout << 1 << '\n';
          int cnt = 0;
          while (u && cnt < (k + 1) / 2) {
            std::cout << u << ' ';
            u = pa[pa[u]];
            cnt++;
          }
          exit(0);
        }
      }
    }
  };
  dfs2(dfs2, 1, 0);
  assert(false);
}