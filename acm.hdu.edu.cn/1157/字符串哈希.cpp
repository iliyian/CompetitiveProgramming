#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int k, c, d, e, f;
  std::cin >> k >> c >> d >> e >> f;
  int Al = 1, Ar = 26, ans = 0;
  for (int i = 1; i <= k; i++, Al = Al * 26 + 1, Ar = Ar * 26 + 26) {
    int l = 0, r = 10006, _l = -1, _r = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int val = mid * mid * mid * c + mid * mid * d + mid * e + f;
      if (val >= Al) r = mid - 1, _l = mid;
      else l = mid + 1;
    }
    l = 0, r = 10006;
    while (l <= r) {
      int mid = (l + r) / 2;
      int val = mid * mid * mid * c + mid * mid * d + mid * e + f;
      if (val <= Ar) l = mid + 1, _r = mid;
      else r = mid - 1;
    }

    if (_l == -1 || _r == -1) continue;
    std::cerr << i << ' ' << _l << ' ' << _r << ' ' << Al << ' ' << Ar << '\n';
  }
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