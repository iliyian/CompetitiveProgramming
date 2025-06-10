// date: 2025-04-11 17:48:50
// tag: 十分神奇的过了。不得不说还是没有模拟清楚导致的。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1);
  std::vector<int> premx(n + 1), sufmx(n + 2), sufmn(n + 2), mxgap(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  premx[0] = LLONG_MIN;
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    premx[i] = std::max(premx[i - 1], s[i]);
  }
  for (int i = n; i >= 1; i--) {
    sufmx[i] = std::max(sufmx[i + 1], s[i]);
    sufmn[i] = std::min(sufmn[i + 1], s[i]);
    mxgap[i] = std::max(mxgap[i + 1], s[n] - s[i]);
  }
  int mxans = mxgap[1], ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (premx[i] > premx[i - 1]) {
      // std::cerr << i << ' ' << mxgap[i + 1] << ' ' << premx[i] << ' ' << mxans << '\n';
      if (premx[i] + mxgap[i + 1] > mxans) {
        ans = premx[i];
        mxans = premx[i] + mxgap[i + 1];
      }
    }
  }
  std::cout << ans << '\n';
  // std::cerr << mxans << '\n';
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