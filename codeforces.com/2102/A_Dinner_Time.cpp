#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, p, q;
  std::cin >> n >> m >> p >> q;
  if (n % p == 0 && n * q != m * p) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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