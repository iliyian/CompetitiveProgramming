#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, x;
  std::cin >> n >> k >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  auto check = [&](int mid) {
    return (mid - 1) / n * a[n] + a[n] - a[n - ((mid - 1) % n + 1)] >= x;
  };
  int l = 0, r = n * k, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  if (ans == -1) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << n * k - ans + 1 << '\n';
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