#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::array<int, 3>> b;
  for (int i = 0; i < q; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    b.push_back({x, y, z});
  }
  for (auto [x, y, z] : b | std::views::reverse) {
    if (a[x] != a[z] && a[y] != a[z] || a[z] > std::min(a[x], a[y])) {
      std::cout << -1 << '\n';
      std::cerr << x << ' ' << y << ' ' << z << '\n';
      return;
    } else {
      a[z] = std::max(a[x], a[y]) + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
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