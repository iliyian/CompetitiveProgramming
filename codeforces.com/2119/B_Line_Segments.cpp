#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  int sx, sy, tx, ty;
  std::cin >> n >> sx >> sy >> tx >> ty;
  std::vector<int> a(n + 1), suf(n + 2), pre(n + 2);
  int d2 = (tx - sx) * (tx - sx) + (ty - sy) * (ty - sy);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int mn = a[1], mx = a[1], l = a[1];
  for (int i = 2; i <= n; i++) {
    if (mn <= a[i] && a[i] <= mx) {
      mn = 0;
    } else if (a[i] > mx) {
      mn = std::abs(mx - a[i]);
    } else {
      mn = std::abs(mn - a[i]);
    }
    mx += a[i];
  }
  std::cout << (mn * mn <= d2 && d2 <= mx * mx ? "Yes" : "No") << '\n';
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