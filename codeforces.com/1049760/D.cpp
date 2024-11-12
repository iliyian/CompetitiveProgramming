#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 2) {
    std::cout << "1 -3 -3 1\n";
    return;
  } else if (n == 3) {
    std::cout << "1 -10 6 6 -10 1\n";
    return;
  }
  std::cout << "1 2 ";
  for (int i = 3; i < n * 2; i++) {
    std::cout << (i & 1 ? -1 : 2) << ' ';
  }
  std::cout << 3 - n << '\n';
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