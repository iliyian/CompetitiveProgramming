#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int g = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] % a[1] == 0) {
      g = std::gcd(a[i] / a[1], g);
    }
  }
  if (g == 1) {
    std::cout << "Yes\n";
    return;
  }
  std::cout << "No\n";
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