#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mx = (1ll << 32) - 1, an = mx;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    an &= a[i];
  }
  if (an == 0) {
    int ans = 0, now = mx;
    for (int i = 1; i <= n; i++) {
      now &= a[i];
      if (now == an) {
        ans++;
        now = mx;
      }
    }
    std::cout << ans << '\n';
  } else {
    std::cout << 1 << '\n';
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