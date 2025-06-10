#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<int> vec = {-1};
  // vec.push_back(LLONG_MAX / 3);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  std::sort(vec.begin() + 1, vec.end());
  vec.erase(std::unique(vec.begin() + 1, vec.end()), vec.end());
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  // for (auto i : vec) std::cerr << i << '\n';
  for (int i = 1; i <= n; i++) {
    auto p = std::lower_bound(vec.begin() + 1, vec.end(), a[i]) - vec.begin() - 1;
    // std::cerr << p << ' ';
    std::cout << std::max(0ll, b[i] * 2 - p) << ' ';
  }
  std::cout << '\n';
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