// date: 2025-02-02 22:28:03
// tag: 根据某种渐进性原理，具体的待会补充

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::priority_queue<std::array<int, 4>> q;
  std::vector<int> a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  std::sort(b.begin() + 1, b.end(), std::greater<>());
  std::sort(c.begin() + 1, c.end(), std::greater<>());
  // for (auto i : a) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  auto calc = [&](int x, int y, int z) {
    return a[x] * b[y] + b[y] * c[z] + c[z] * a[x];
  };
  std::set<std::array<int, 3>> vis;
  q.push({calc(1, 1, 1), 1, 1, 1});
  while (!q.empty()) {
    auto [v, x, y, z] = q.top(); q.pop();
    if (vis.count(std::array<int, 3>{x, y, z})) continue;
    vis.insert(std::array<int, 3>{x, y, z});
    // std::cerr << v << '\n';
    if (!--k) {
      std::cout << v << '\n';
      return;
    }
    if (x + 1 <= n) {
      q.push({calc(x + 1, y, z), x + 1, y, z});
    }
    if (y + 1 <= n) {
      q.push({calc(x, y + 1, z), x, y + 1, z});
    }
    if (z + 1 <= n) {
      q.push({calc(x, y, z + 1), x, y, z + 1});
    }
  }
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