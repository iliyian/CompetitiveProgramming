#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) {
      cnt1++;
    } else if (cnt[i] > 1) {
      ans++;
    }
  }
  ans += (cnt1 + 1) / 2 * 2;
  std::cout << ans << '\n';
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