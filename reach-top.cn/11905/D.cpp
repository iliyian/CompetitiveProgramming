#include <bits/stdc++.h>

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j < i; j++) {
			ans += a[i] > a[j];
		}
		std::cout << ans << ' ';
	}
	return 0;
}