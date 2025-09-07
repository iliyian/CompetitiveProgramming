#include <bits/stdc++.h>
#define int long long

auto get(int x) {
  int ans1 = 0, ans2 = 0;
  for (int i = 2; i <= x; i *= 2) {
    ans1 += x / i;
  }
  for (int i = 5; i <= x; i *= 5) {
    ans2 += x / i;
  }
  return std::pair{ans1, ans2};
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  auto [x1, y1] = get(r);
  auto [x2, y2] = get(l - 1);
  std::cout << std::min(x1 - x2, y1 - y2) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}