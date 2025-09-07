#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  if (n <= a) {
    std::cout << "Sayonara\n";
    return;
  }
  int r = n % (a + b);
  if (r == 0 || r >= a + 1) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << r << '\n';
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