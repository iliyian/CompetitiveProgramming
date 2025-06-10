#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  auto dfs = [&](auto self, int n) -> std::pair<int, int> {
    if (n < k) return {0, 0};
    int mid = n / 2;
    auto [x, y] = self(self, n / 2);
    if (n % 2 == 0) {
      return {x + x + y * mid, y * 2};
    }
    return {x + x + y * (mid + 1) + mid + 1, y * 2 + 1};
  };
  std::cout << dfs(dfs, n).first << '\n';
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