#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int mn = LLONG_MAX, mx = LLONG_MIN;
  int sum = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mn = std::min(mn, a[i]), mx = std::max(mx, a[i]);
    sum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    cnt += a[i] == mx;
  }
  if (mx - mn > k + 1 || mx - mn == k + 1 && cnt != 1) {
    std::cout << "Jerry\n";
    return;
  }
  std::cout << (sum % 2 ? "Tom" : "Jerry") << '\n';
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