#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 100, w = 100000;
  std::cout << t << '\n';
  while (t--) {
    int l = rd() % w + 1, r = rd() % w + 1;
    if (l > r) std::swap(l, r);
    std::cout << 1 << ' ' << r << '\n';
  }

  return 0;
}