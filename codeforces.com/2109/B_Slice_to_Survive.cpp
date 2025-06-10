#include <bits/stdc++.h>
#define int long long

std::map<std::array<int, 4>, int> mp;

void solve() {
  int n, m, x, y;
  std::cin >> n >> m >> x >> y;
  x = std::min(x, n - x + 1), y = std::min(y, m - y + 1);
  auto get = [&](auto self, int x) {
    if (x == 1) return 0;
    return 1 + self(self, (x + 1) / 2);
  };
  int ans = std::min(get(get, n) + get(get, y), get(get, m) + get(get, x)) + 1;
  std::cout << ans << '\n';
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