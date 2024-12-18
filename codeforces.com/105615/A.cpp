#include <bits/stdc++.h>
#define int long long

void solve() {
	int x;
	std::cin >> x;
	int mx = 1;
//	std::cout << x << '\n';
	for (int i = 1; i <= 2024; i++) {
		if (i * x % 2024 > mx * x % 2024) {
			mx = i;
//			std::cout << mx << '\n';
		}
	}
	std::cout << mx << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
