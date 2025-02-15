#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end());
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i].second;
    if (sum > a[i].first * k) {
      std::cout << "No\n";
      // std::cout << sum << '\n';
      return;
    } 
  }
  std::cout << "Yes\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}