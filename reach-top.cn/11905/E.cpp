#include <bits/stdc++.h>

signed main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
	int l = 1, r = n, ans = 0;
	while (l <= n && a[l] <= k) l++, ans++;
	while (r >= 1 && a[r] <= k) r--, ans++;
	std::cout << std::min(ans, n) << '\n';
  return 0;
}