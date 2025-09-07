#include <bits/stdc++.h>
#define int long long

// int lcm(int a, int b) {
//   return a * b / std::gcd(a, b);
// }

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  std::set<std::pair<int, int>> s;
  auto dfs = [&](auto self, int u, int p, int val, int rt) -> void {
    val = std::lcm(val, a[u]);
    if (val == x) {
      s.insert({std::min(u, rt), std::max(u, rt)});
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, val, rt);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    dfs(dfs, i, 0, 1, i);
  }
  std::cout << s.size() << '\n';
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