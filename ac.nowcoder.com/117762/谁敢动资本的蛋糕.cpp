#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i <= 40; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += a[j] >> i & 1;
    }
    ans += ((cnt / 2) * 2) << i;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}