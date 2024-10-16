#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    char x;
    std::cin >> x;
    a[i] = x - '0';
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1) ans += a[i] * 10;
    else if (i == n) ans += a[i];
    else ans += a[i] * 11;
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}