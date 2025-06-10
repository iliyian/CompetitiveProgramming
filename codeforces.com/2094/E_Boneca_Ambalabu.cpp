#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cnt[31] {};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 0; j <= 30; j++) {
      cnt[j] += a[i] >> j & 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 0; j <= 30; j++) {
      if (a[i] >> j & 1) {
        cur += (n - cnt[j]) << j;
      } else {
        cur += cnt[j] << j;
      }
    }
    ans = std::max(ans, cur);
  }
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