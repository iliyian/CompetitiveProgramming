#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n == 1 || n % 4 == 0) {
    std::cout << "impossible\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1 || i % 4 == 0) {
      if (i != n) {
        std::cout << i << ' ';
      }
      std::cout << i - 1 << ' ';
      i++;
    } else {
      std::cout << i - 1 << ' ';
    }
  }
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