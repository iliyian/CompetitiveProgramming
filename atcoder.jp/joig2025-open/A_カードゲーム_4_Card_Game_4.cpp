#include <bits/stdc++.h>
#include <numeric>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::array<std::vector<int>, 2> a;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[x % 2].push_back(x);
  }
  std::sort(a[0].rbegin(), a[0].rend());
  std::sort(a[1].rbegin(), a[1].rend());
  int ans = 0;
  if (a[0].size() >= k) {
    ans = std::max(ans, std::accumulate(a[0].begin(), a[0].begin() + k, 0ll));
  }
  if (a[1].size() >= k) {
    ans = std::max(ans, std::accumulate(a[1].begin(), a[1].begin() + k, 0ll));
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