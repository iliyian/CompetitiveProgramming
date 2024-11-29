#include <bits/stdc++.h>
#define int long long

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n;
  std::cin >> n;
  if (n <= 4) {
    std::cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i += 2) {
    if (i != 5) {
      std::cout << i << ' ';
    }
  }
  std::cout << 5 << ' ';
  std::cout << 4 << ' ';
  for (int i = 2; i <= n; i += 2) {
    if (i != 4) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
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