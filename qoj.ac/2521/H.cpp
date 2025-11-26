#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = a[i] - i;
  }
  b[n + 1] = LLONG_MAX / 3;
  for (int i = n; i >= 1; i--) {
    b[i] = std::min(b[i + 1], b[i]);
    if (b[i] < 0) {
      std::cout << -1 << '\n';
      return;
    }
  }
  int ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int t = std::min(b[i + 1] + i, a[i]) - ans;
    sum = std::max(sum - (t - 1), 0ll);
    ans += t;
    sum += a[i] - ans;
  }
  std::cout << ans + sum << '\n';
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