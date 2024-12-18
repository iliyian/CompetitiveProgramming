#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, y;
  std::cin >> x >> y;
  std::vector<int> facx, facy;
  for (int i = 1; i * i <= std::max(x, y); i++) {
    if (x % i == 0) {
      facx.push_back(i);
      if (i * i != x) {
        facx.push_back(x / i);
      }
    }
    if (y % i == 0) {
      facy.push_back(i);
      if (i * i != y) {
        facy.push_back(y / i);
      }
    }
  }
  std::sort(facx.begin(), facx.end());
  std::sort(facy.begin(), facy.end());
  // std::cout << facx.size() << ' ' << facy.size() << '\n';
  int ans = 0;
  for (auto a : facx) {
    for (auto b : facy) {
      __int128 g = a * b / std::gcd(a, b);
      int l = 1, r = y, p = -1;
      while (l <= r) {
        __int128 mid = (l + r) / 2;
        if (mid * g > x) r = mid - 1, p = mid;
        else l = mid + 1;
      }
      if (p != -1 && p * g < y && p * g > x) {
        // std::cout << a << ' ' << b << ' ' << p << '\n';
        ans = std::max(ans, a + b);
      }
    }
  }
  std::cout << ans << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("G.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
