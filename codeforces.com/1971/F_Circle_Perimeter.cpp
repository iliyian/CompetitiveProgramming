#include <bits/stdc++.h>
#define int long long

int get(int r) {
  int ans = 0;
  for (int x = 1; x < r; x++) {
    int _l = 0, _r = r + 1, y = -1;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (x * x + mid * mid < r * r) _l = mid + 1, y = mid;
      else _r = mid - 1;
    }
    ans += y * 2 + 1;
  }
  return ans * 2 + r * 2 - 1;
}

void solve() {
  int r;
  std::cin >> r;
  std::cout << get(r + 1) - get(r) << '\n';
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