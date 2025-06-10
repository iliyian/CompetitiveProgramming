// date: 2025-03-27 18:14:25
// tag: 神奇贪心，观察到贪心的性质，然后特判小范围的几种情况即可，二进制

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::cin >> a >> b;
  a = '#' + a, b = '#' + b;
  std::vector<int> sa(n + 1), sb(n + 1);
  for (int i = 2; i <= n - 1; i++) {
    if (a[i - 1] == '0' && a[i + 1] == '0' && b[i] != '1') {
      b[i] = '1';
      sb[i] = 1;
    }
  }
  for (int i = 2; i <= n - 1; i++) {
    if (b[i - 1] == '1' && b[i + 1] == '1' && a[i] != '1') {
      a[i] = '1';
      sa[i] = 1;
    }
  }
  std::vector<int> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (a[i] == '1');
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int ans = sum[r] - sum[l - 1];
    if (l == r) {
      if (sa[l]) ans--;
      std::cout << ans << '\n';
      continue;
    }
    if (l == r - 1) {
      if (sa[l]) ans--;
      if (sa[r]) ans--;
      std::cout << ans << '\n';
      continue;
    }
    if (l == r - 2) {
      if (sa[l]) ans--;
      if (sa[r]) ans--;
      if (sa[l + 1] && (sb[l] || sb[r])) ans--;
      std::cout << ans << '\n';
      continue;
    }
    if (sa[l]) ans--;
    if (sa[r]) ans--;
    if (sb[l] && sa[l + 1]) ans--;
    if (sb[r] && sa[r - 1]) ans--;
    std::cout << ans << '\n';
  }
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