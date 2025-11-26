#include <bits/stdc++.h>
#define int long long

std::vector<int> f;

void solve() {
  int s, l, r;
  std::cin >> s >> l >> r;
  std::cout << r - l + 1 << '\n';
  // auto p = std::ranges::lower_bound(f, s) - f.begin();
  // if (f[p] != s) {
  //   std::cout << 0 << '\n';
  //   return;
  // }
  // auto lo = std::ranges::lower_bound(f, l);
  // auto hi = std::ranges::upper_bound(f, r);
  // std::cout << hi - lo << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f.push_back(1);
  f.push_back(2);
  for (int i = 1; i <= 100000; i++) {
    f.push_back(i * i + i * 2);
    f.push_back(i + 2);
  }
  std::ranges::sort(f);
  f.erase(std::unique(f.begin(), f.end()), f.end());
  // std::cout << f.size() << '\n';
  // for (int i : f) {
  //   std::cerr << i << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}