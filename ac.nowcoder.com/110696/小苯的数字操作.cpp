#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0;
  for (int i = 0; i <= 30; i++) {
    if (k < i)
      continue;
    ans++;
    if ((n >> i) == 0)
      break;
    if (i == 0 || (n >> i & 1 ^ 1) && (n >> (i - 1) & 1)) {
      ans += k - i;
    } else if ((n >> i & 1) && (n >> (i - 1) & 1)) {
      ans += k - i;
      // std::cerr << i << ' ' << ans << '\n';
    }
  }
  // std::cout << ans + (64 - __builtin_clzll(n)) << '\n';
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