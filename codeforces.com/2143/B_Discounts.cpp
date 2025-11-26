#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(k + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> b[i];
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  std::sort(b.begin() + 1, b.end());
  int ans = 0, t = b[1], j = 1;
  for (int i = 1; i <= n; i++) {
    if (i == t) {
      ans += 0;
      if (j + 1 <= k) {
        t += b[++j];
      }
    } else {
      ans += a[i];
    }
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