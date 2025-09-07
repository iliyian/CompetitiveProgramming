#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = n + n - 1;
  auto check = [&](int i, int j, int k) {
    return a[i] <= a[j] && a[j] <= a[k] || a[i] >= a[j] && a[j] >= a[k];
  };
  for (int i = 2; i <= n - 1; i++) {
    if (!check(i - 1, i, i + 1)) {
      ans++;
    }
  }
  for (int i = 1; i <= n - 3; i++) {
    if (!check(i, i + 1, i + 2) && !check(i, i + 2, i + 3) && !check(i + 1, i + 2, i + 3) && !check(i, i + 1, i + 3)) {
      ans++;
    }
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