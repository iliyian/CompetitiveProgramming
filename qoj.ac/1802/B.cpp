#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  std::sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
    return k - x % k < k - y % k;
  });
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = std::min(m, k - a[i] % k);
    m -= x;
    a[i] += x;
    ans += a[i] / k;
  }
  std::cout << ans + m / k << '\n';
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