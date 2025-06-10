// date: 2025-05-15 00:07:42
// tag: 看起来环的处理确实没有什么令人眼前一亮的特别优秀的写法？相当朴素的基环树贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), c(n + 1);
  std::vector<int> in(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    in[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::vector<int> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!in[i] && !vis[i]) {
      std::cout << i << ' ';
      vis[i] = 1;
      int u = a[i];
      while (!--in[u]) {
        vis[u] = 1;
        std::cout << u << ' ';
        u = a[u];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] && !vis[i]) {
      std::vector<int> b = {i};
      int u = a[i];
      while (u != i) {
        b.push_back(u);
        u = a[u];
      }
      std::sort(b.begin(), b.end(), [&](const int &x, const int &y) {
        return c[x] < c[y];
      });
      int v = a[b[0]];
      std::cout << v << ' ';
      u = a[v];
      vis[v] = 1;
      while (u != v) {
        vis[u] = 1;
        std::cout << u << ' ';
        u = a[u];
      }
    }
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