// date: 2024-12-17 18:39:25
// tag: 有意思的滑动窗口

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int n = str.size() - 1;
  int mxa = 1, mxb = 1;
  for (int i = 1; i <= 26; i++) {
    std::vector<int> cnt(26);
    auto count = [&]() {
      return cnt.size() - std::count(cnt.begin(), cnt.end(), 0);
    };
    for (int l = 1, r = 1; l <= n; --cnt[str[l++] - 'a']) {
      while (r <= n && count() <= i) ++cnt[str[r++] - 'a']; // [l,r)
      int c = count(); c *= c;
      int d = r - l;
      if (c * mxb > d * mxa) {
        mxa = c, mxb = d;
      }
    }
  }
  int g = std::gcd(mxa, mxb);
  std::cout << mxa / g << ' ' << mxb / g << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("E.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
