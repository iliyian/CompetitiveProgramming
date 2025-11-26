#include <bits/stdc++.h>
#define int long long

void solve() {
  std::vector<double> p = {
    0.310035697652,
0.473324044845,
0.574114878920,
0.642525378583,
  };
  std::map<int, double> mp;
  for (int i = 0; i < (1ll << 4); i++) {
    double pr = 1;
    int prod = 1;
    for (int j = 0; j < 4; j++) {
      if (i >> j & 1) {
        pr *= p[j];
        prod *= j + 1;
      } else {
        pr *= 1 - p[j];
      }
    }
    if (__builtin_popcountll(i) == 2) {
      mp[prod] = pr;
    }
  }
  for (auto [k, v] : mp) {
    std::cout << k << ' ' << v << '\n';
  }
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