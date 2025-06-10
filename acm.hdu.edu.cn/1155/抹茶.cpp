#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int prv = 1, prvsum = a[1] + b[1], ans = 0, suma = a[1];
  for (int i = 2; i <= n; i++) {
    int sum = a[i] + b[i];
    if (sum != prvsum) {
      ans = std::max(ans, suma * (i - prv));
      prvsum = sum;
      prv = i;
      suma = 0;
    }
    suma += a[i];
  }
  ans = std::max(ans, (n + 1 - prv) * suma);
  std::cout << ans << '\n';
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