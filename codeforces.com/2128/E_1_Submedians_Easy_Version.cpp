#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cout << std::bit_width(123) << '\n';
  auto check = [&](int mid) -> bool {
    auto b = a;
    int mn = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = (a[i] >= mid ? 1 : -1) + b[i - 1];
    }
    for (int i = k; i <= n; i++) {
      if (b[i] >= b[mn]) {
        return true;
      }
      if (b[i - k + 1] < b[mn]) {
        mn = i - k + 1;
      }
    }
    return false;
  };
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << ' ';
  for (int i = 1; i <= n; i++) {
    a[i] = (a[i] >= ans ? 1 : -1) + a[i - 1];
  }
  int mn = 0;
  for (int i = k; i <= n; i++) {
    if (a[i] >= a[mn]) {
      std::cout << mn + 1 << ' ' << i << '\n';
      return;
    }
    if (a[i - k + 1] < a[mn]) {
      mn = i - k + 1;
    }
    // mn = std::min(mn, a[i - k + 1]);
  }
  // std::cout << "?\n";
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