#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int ecnt = 0, ocnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ecnt += a[i] % 2 == 0;
    ocnt += a[i] % 2 == 1;
  }
  if (!ecnt) {
    std::cout << ocnt - 1 << '\n';
  } else {
    std::cout << ocnt + 1 << '\n';
  }
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