#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), c(n + 1);
  int asum = 0, bsum = 0, csum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    asum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    bsum += b[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
    csum += c[i];
  }
  std::cout << (csum - bsum) / asum << '\n';
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