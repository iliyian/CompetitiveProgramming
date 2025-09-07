#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n + 1);
  bool f = false, g = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    f |= a[i];
    g |= !a[i];
  }
  if (!f) {
    std::cout << -1 << '\n';
    return;
  }
  if (!g) {
    for (int i = 1; i <= n - 1; i++) {
      if (x) {
        x--;
        std::cout << 0 << ' ';
      } else {
        y--;
        std::cout << 1 << ' ';
      }
    }
    std::cout << '\n';
    return;
  }
  if (a[1] == 1) {
    if (!x) {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << 0 << ' ';
    x--;
    for (int i = 2; i <= n - 1; i++) {
      if (x) {
        x--;
        std::cout << 0 << ' ';
      } else {
        y--;
        std::cout << 1 << ' ';
      }
    }
    std::cout << '\n';
    return;
  }
  if (a[n] == 1) {
    if (!x) {
      std::cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= n - 1; i++) {
      if (y) {
        y--;
        std::cout << 1 << ' ';
      } else {
        x--;
        std::cout << 0 << ' ';
      }
    }
    std::cout << '\n';
    return;
  }
  if (x < 2) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> ans(n, -1);
  int cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == 0 && a[i + 1] == 1) {
      ans[i] = 0;
      cnt++;
    }
    if (a[i] == 1 && a[i + 1] == 0) {
      ans[i] = 0;
      cnt++;
    }
    if (cnt == 2) {
      break;
    }
  }
  x -= 2;
  for (int i = 1; i <= n - 1; i++) {
    if (ans[i] == -1) {
      if (x) {
        x--, ans[i] = 0;
      } else {
        y--, ans[i] = 1;
      }
    }
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
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