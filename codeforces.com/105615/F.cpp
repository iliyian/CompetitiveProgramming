#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt += a[i] == 0 || a[i] == 2;
  }
  if (!cnt) {
    std::cout << 0 << '\n';
  } else {
    std::cout << qpow(2, cnt - 1) - 1 << '\n';
  }
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("F.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
