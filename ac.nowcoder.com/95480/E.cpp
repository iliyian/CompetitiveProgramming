#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<char> s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> s[i];
  }
  int m;
  std::cin >> m;
  char x, y;
  if (m == 1) {
    int ans = 0;
    std::cin >> x;
    for (int i = 1; i <= n; i++) {
      ans += a[i] * (s[i] == x);
    }
    std::cout << ans << '\n';
    return;
  }
  std::cin >> x >> y;
  int ans = 0;
  if (x != y) {
    for (int i = 1; i < n; i++) {
      ans += (s[i] == x && s[i + 1] == y);
    }
  } else {
    for (int i = 1; i <= n; i++) {
      ans += (s[i] == x) * (a[i] - 1);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}