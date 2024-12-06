// date: 2024-12-04 22:52:51
// tag: 脑子太混沌了属于是，d是前缀不是前缀和，草

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int ans = k, d = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 1, j = i;
    while (j + 1 <= n && a[j + 1] == a[j]) j++, cnt++;
    if (k > (a[i] - d) * (n - i + 1)) {
      k -= (a[i] - d) * (n - i + 1);
    } else {
      std::cout << ans << '\n';
      return;
    }
    ans += cnt;
    d = a[i];
    i = j;
  }
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