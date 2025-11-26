#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = n / 6 * 2;
  if (n == 2 || n == 4) {
    std::cout << -1 << '\n';
    return;
  }
  if (n % 6 == 1) {
    ans--;
  }
  if (n % 6 == 3) {
    ans++;
  }
  if (n % 6 == 5) {
    ans++;
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