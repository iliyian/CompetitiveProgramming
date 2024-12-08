#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }
  std::sort(a.begin(), a.end(), [&](const int &x, const int &y) {
    int vx = 0, tx = x, vy = 0, ty = y;
    while (tx) vx += tx % 10, tx /= 10;
    while (ty) vy += ty % 10, ty /= 10;
    return std::tie(vx, x) > std::tie(vy, y);
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