#include <bits/stdc++.h>
#include <cctype>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  std::sort(a.begin(), a.end(), [&](const int &x, const int &y) {
    int xs = 0, ys = 0, xx = x, yy = y;
    while (xx) xs += xx % 10, xx /= 10;
    while (yy) ys += yy % 10, yy /= 10;
    return xs < ys;
  });
  for (auto i : a) {
    std::cout << i << ' ';
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