#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mn = 1, mx = 1;
  for (int i = 1; i <= n; i++) {
    char x;
    std::cin >> x;
    a[i] = x - '0';
    if (a[i] >= a[mx]) mx = i;
    if (a[i] < a[mn]) mn = i;
  }
  if (n == 1) {
    std::cout << 0 << ' ' << 0 << '\n';
    return;
  }
  int op = 0;
  if (a[mn] == a[mx]) op = 1;
  else {
    if (a[mn] == a[1] && a[mx] == a[n]) op = 0;
    else if (a[mn] == a[n] && a[mx] == a[1]) op = 1;
    else op = 2;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == mn) ans += a[i] * 10;
    else if (i == mx) ans += a[i];
    else ans += a[i] * 11;
  }
  std::cout << op << ' ' << ans << '\n';
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