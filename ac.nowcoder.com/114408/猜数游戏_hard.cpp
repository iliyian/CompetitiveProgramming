#include <bits/stdc++.h>
#define int long long

int get(int n) {
  int x = 63 - __builtin_clzll(n);
  if ((1 << x) == n) {
    return x;
  } else {
    return x + 1;
  }
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (k == 1) {
    std::cout << get(n) << '\n';
    return;
  }
  __int128_t r[101] {};
  r[1] = __int128_t(1) * k * k;
  if (r[1] >= n) {
    std::cout << get(1) << '\n';
    return;
  }
  for (int i = 2;; i++) {
    r[i] = r[i - 1] * k * k + k * k;
    if (r[i] >= n) {
      std::cout << get(i) << '\n';
      return;
    }
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