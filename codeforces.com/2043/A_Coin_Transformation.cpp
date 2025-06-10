#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  auto dfs = [&](auto self, int u) -> int {
    if (u <= 3) return 1;
    return 2 * self(self, u / 4);
  };
  std::cout << dfs(dfs, n) << '\n';
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