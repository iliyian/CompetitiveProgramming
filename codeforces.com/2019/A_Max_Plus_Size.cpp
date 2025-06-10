#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mx[2] {-1, -1};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[i % 2] = std::max(mx[i % 2], a[i]);
  }
  std::cout << std::max((n + 1) / 2 + mx[1], n / 2 + mx[0]) << '\n';
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