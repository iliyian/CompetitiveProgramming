#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, d;
  std::cin >> n >> d;
  std::cout << 1 << ' ';
  if (n >= 3 || d % 3 == 0) std::cout << 3 << ' ';
  if (d % 5 == 0) std::cout << 5 << ' ';
  if (n >= 3 || d == 7) std::cout << 7 << ' ';
  if (n >= 6 || d % 9 == 0 || n >= 3 && d % 3 == 0) std::cout << 9 << ' ';
  std::cout << '\n';
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