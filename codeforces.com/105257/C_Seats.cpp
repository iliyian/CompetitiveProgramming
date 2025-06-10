// date: 2025-03-03 22:13:05
// tag: 一颗内向基环树森林，基环树森林具有很多有意思的性质，内向的也具有很多有意思的性质，我还有时间学习吗
// 这题是如此明晰，基于拓扑排序的最长路dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), in(n * 2 + 1);
  std::vector<std::vector<int>> g(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    in[a[i]]++;
    g[i].push_back(a[i]);
  }
  std::vector<int> vis(n * 2 + 1), f(n * 2 + 1);
  std::queue<int> q;
  for (int i = 1; i <= n * 2; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  int ans = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (g[u].empty()) {
      ans += f[u];
      continue;
    }
    for (int v : g[u]) {
      if (!--in[v]) {
        f[v] = std::max(f[v], f[u] + 1);
        q.push(v);
      }
    }
  }
  // std::cerr << ans << '\n';
  for (int i = 1; i <= n * 2; i++) {
    if (in[i]) {
      ans++;
    }
  }
  std::cout << ans << '\n';
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