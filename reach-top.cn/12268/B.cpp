#include <bits/stdc++.h>
#define int long long

int calc(int x) {
  int ans = 0;
  while (x) ans += x % 10, x /= 10;
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end(), [&](const int &x, const int &y) {
    int xx = x, yy = y, x0 = x & 1, y0 = y & 1, cx = calc(x), cy = calc(y);
    return std::tie(x0, cx, xx) < std::tie(y0, cy, yy);
  });
  for (auto x : a) {
    std::cout << x << ' ';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}