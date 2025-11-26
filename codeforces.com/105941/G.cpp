#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 1 || n == 4) {
    std::cout << -1 << '\n';
    return;
  }
  if (n == 2) {
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }
  if (n == 3) {
    std::cout << 1 << ' ' << 2 << '\n';
    std::cout << 2 << ' ' << 3 << '\n';
    return;
  }
  int k = (n + 1) / 3;
  for (int i = 2; i <= k * 2; i++) {
    std::cout << i - 1 << ' ' << i << '\n';
  }
  int s = k * 2 + 1;
  for (int i = s; i < s + k - 1; i++) {
    std::cout << 2 << ' ' << i << '\n';
  }
  if (n % 3 == 0) {
    std::cout << k * 2 << ' ' << n << '\n';
  }
  if (n % 3 == 1) {
    std::cout << k * 2 << ' ' << n - 1 << '\n';
    std::cout << 3 << ' ' << n << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);
  // freopen("d.out", "w", stdout);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
    // std::cout << '\n';
  }

  return 0;
}