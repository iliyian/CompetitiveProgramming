#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mx = LLONG_MIN, mn = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int mx0 = LLONG_MIN / 3, mx1 = LLONG_MIN / 3, mn0 = LLONG_MAX / 3, mn1 = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    if (a[i] % 2 == 0) {
      mn0 = std::min(mn0, i);
      mx0 = i;
    } else {
      mn1 = std::min(mn1, i);
      mx1 = i;
    }
  }
  std::cout << std::min(mn0 - 1 + n - mx0, mn1 - 1 + n - mx1) << '\n';
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