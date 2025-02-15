#include <bits/stdc++.h>
#define int long long

std::set<int> s = {1, 4, 7, 29, 35, 36, 37, 41, 42, 43, 44, 45, 47, 48, 49};

void solve(int x) {
  if (s.count(x)) {
    std::cout << 1 << '\n' << 1 << '\n';
  } else {
    int n = 1000;
    std::cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << (int)(1e9) * (i <= n / 2 + 1 ? 1 : -1)<< ' ';
    }
    std::cout << '\n';
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