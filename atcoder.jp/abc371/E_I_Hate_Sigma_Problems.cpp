#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pre(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += (i - pre[a[i]]) * (n - i + 1); // 当前作为某个区间的首个某个值对其做贡献，这样的区间个数
    pre[a[i]] = i;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}