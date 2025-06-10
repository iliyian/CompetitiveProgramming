#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if ((a + b + c) % 3) {
    std::cout << "NO\n";
    return;
  }
  int t = (a + b + c) / 3;
  if (a <= t && b <= t && c >= t && c - t >= t - a + t - b) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
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