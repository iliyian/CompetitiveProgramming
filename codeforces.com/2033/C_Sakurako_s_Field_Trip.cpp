#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int l = 1, r = n;
  while (l <= r) {
    if (a[l] == a[l - 1] || a[r] == a[r + 1]) std::swap(a[l], a[r]);
    l++, r--;
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    ans += a[i] == a[i + 1];
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