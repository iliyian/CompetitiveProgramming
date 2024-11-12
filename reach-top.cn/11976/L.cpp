#include <bits/stdc++.h>
#define int long long

void solve(int n) {
  int k = n & -n;
  int cnt = __builtin_popcountll(n), t = k;
  if (n & 1) {
    if (n == 1) {
      std::cout << 2 << '\n';
      return;
    }
    k = 1;
  }
  n += k;
  if (__builtin_popcountll(n) < cnt) {
    n += (1 << (cnt - __builtin_popcountll(n))) - 1;
  }
  std::cout << n << '\n';
  assert(__builtin_popcountll(n) == cnt);
}

signed main() {
  int t = 1;
  // std::cin >> t;
  int n;
  while (std::cin >> n, n) {
    solve(n);
  }
  return 0;
}