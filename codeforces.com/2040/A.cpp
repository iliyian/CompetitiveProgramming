#include <bits/stdc++.h>
#define int long long

constexpr int N = 6e5;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    bool f = true;
    for (int j = 1; j <= n; j++) {
      if (i != j && std::abs(a[i] - a[j]) % k == 0) {
        f = false;
        break;
      }
    }
    if (f) {
      std::cout << "YES\n";
      std::cout << i << '\n';
      return;
    }
  }
  std::cout << "NO\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
