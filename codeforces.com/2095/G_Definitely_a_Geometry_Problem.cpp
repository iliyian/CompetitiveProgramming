#include <bits/stdc++.h>
#define int long long

const double pi = acos(-1);

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end());
  long double ans = LDBL_MAX;
  for (int i = 1; i + k - 1 <= n; i++) {
    int j = i + k - 1;
    long double d = sqrtl(__int128(a[j].second - a[i].second) * (a[j].second - a[i].second) + __int128(a[j].first - a[i].first) * (a[j].first - a[i].first));
    ans = std::min(ans, pi * (d / 2) * (d / 2));
  }
  std::cout << std::fixed << std::setprecision(20) <<  ans << '\n';
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