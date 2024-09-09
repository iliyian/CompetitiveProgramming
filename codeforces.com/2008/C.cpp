#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int l, r;
  std::cin >> l >> r;
  // l + (x + 1) * x / 2 <= r
  int L = 0, R = INT_MAX;
  while (L < R - 1) {
    int mid = (L + R) / 2;
    if (l + mid * (mid + 1) / 2 <= r) L = mid;
    else R = mid - 1;
  }
  if (l + R * (R + 1) / 2 <= r) L = R;
  std::cout << L + 1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}