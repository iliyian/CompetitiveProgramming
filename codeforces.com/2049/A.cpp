#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  bool f = false, g = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i]) {
      f = true;
    } else {
      g = true;
    }
  }
  if (!f) {
    std::cout << 0 << '\n';
    return;
  }
  if (!g) {
    std::cout << 1 << '\n';
    return;
  }
  int l = 1, r = n;
  while (l <= n && a[l] == 0) l++;
  while (r >= l && a[r] == 0) r--;
  for (int i = l; i <= r; i++) {
    if (a[i] == 0) {
      std::cout << 2 << '\n';
      return;
    }
  }
  std::cout << 1 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}