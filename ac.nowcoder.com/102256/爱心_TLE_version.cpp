#include <bits/stdc++.h>
#define int long long

std::set<int> s = {1, 4, 7, 29, 35, 36, 37, 41, 42, 43, 44, 45, 47, 48, 49};

void solve(int x) {
  if (s.count(x)) {
    std::cout << 1 << ' ' << 1 << '\n';
    std::cout << 1 << '\n';
    std::cout << 1 << ' ' << 1 << '\n';
  } else {
    int n = 1e4, q = 1e4;
    std::cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << 1 << ' ';
    }
    std::cout << '\n';
    for (int i = 1; i <= q; i++) {
      std::cout << 1 << ' ' << n << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 49;
  // std::cin >> t;
  std::cout << t << '\n';
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}