#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0;
  if (n % 2 == 1) {
    ans++;
    n -= k;
    ans += n / (k - 1);
    if (n % (k - 1)) ans++;
  } else {
    ans = (n + k - 2) / (k - 1);
  }
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