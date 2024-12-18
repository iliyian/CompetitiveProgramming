#include <bits/stdc++.h>
#define int long long

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void solve() {
	int x, y;
	std::cin >> x >> y;
	int z = 0, g = 0;
	for (int i = x + 1; i < y; i++) {
		int t = gcd(x, i) + gcd(i, y);
		if (t > g) {
			g = t;
			z = i;
		}
	}
	std::cout << g << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
