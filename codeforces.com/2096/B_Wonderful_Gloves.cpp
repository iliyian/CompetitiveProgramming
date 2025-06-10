#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> l(n + 1), r(n + 1);
  int mx = 0, suml = 0, sumr = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> r[i];
  }
  std::vector<int> c(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = std::min(l[i], r[i]);
    ans += std::max(l[i], r[i]);
  }
  std::sort(c.begin() + 1, c.end(), std::greater<>());
  for (int i = 1; i <= k - 1; i++) {
    ans += c[i];
  }
  ans++;
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