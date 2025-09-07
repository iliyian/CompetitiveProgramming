#include <bits/stdc++.h>
#define int long long

int get(int x) {
  if (x == 1) return 0;
  int p[4] = {2, 3, 5, 7};
  int ans = x;
  for (int i = 0; i < (1 << 4); i++) {
    int y = 1;
    for (int j = 0; j < 4; j++) {
      if (i >> j & 1) {
        y *= p[j];
      }
    }
    ans += (__builtin_popcountll(i) % 2 ? 1 : -1) * (x / y);
  }
  return ans;
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  std::cout << (r - l + 1 - (get(r) - get(l - 1))) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 2; i <= 100; i++) {
  //   std::cerr << i << ' ' << get(i) << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}