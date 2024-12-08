#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> cnt(10);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (cnt[a[i]]) {
      std::fill(cnt.begin(), cnt.end(), 0);
      ans++;
    }
    cnt[a[i]]++;
  }
  std::cout << ans << ' ' << n << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}