#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cnt1 = 0, cnt0 = 0, mn = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == 0) cnt0++;
    else if (a[i] < 0) cnt1++;
    if (a[i] != 0) {
      mn = std::min(mn, std::abs(a[i]));
    }
  }
  if (cnt1 % 2 == 0) {
    std::cout << cnt0 << '\n';
  } else {
    if (cnt0) {
      std::cout << cnt0 << '\n';
    } else {
      std::cout << mn + 1 << '\n';
    }
  }
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