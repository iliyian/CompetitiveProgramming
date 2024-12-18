#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << '\n';
    return;
  }
  int x = 2;
  for (int i = 1; i <= n; i++) {
    std::cout << x << ' ';
    x += 2;
    if (i == n / 2) {
      x = 1;
    }
  }
  std::cout << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("D.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
