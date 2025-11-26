#include <bits/stdc++.h>
#define int long long

void solve() {
  int k, x;
  std::cin >> k >> x;
  int i = 0;
  while (x >> i & 1 ^ 1) i++;
  std::vector<int> ans;
  for (int j = i + 1; j <= k; j++) {
    if (x >> j & 1) {
      ans.push_back(2);
    } else {
      ans.push_back(1);
    }
  }
  std::cout << ans.size() << '\n';
  // int now = 1ll << k;
  for (auto i : ans) {
    std::cout << i << ' ';
    // if (i == 1) {
    //   now /= 2;
    // } else {
    //   now = now / 2 + (1ll << k);
    // }
  }
  std::cout << '\n';
  // std::cerr << now << ' ' << x << '\n';
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