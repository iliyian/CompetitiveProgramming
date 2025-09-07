#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  int d = std::abs(a * a - b * b);
  if (d == 3) {
    std::cout << 1 << '\n';
  } else if (d == 5) {
    std::cout << 2 << '\n';
  } else if (d == 7) {
    std::cout << 3 << '\n';
  } else if (d == 8) {
    std::cout << 4 << '\n';
  } else {
    if (d % 4 == 0) {
      std::cout << (d / 4 - 2) * 3 + 4 << '\n';
    } else {
      std::cout << ((d % 4 == 1 ? 1 : 2) + (d / 4 - 2) * 3 + 4) << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  std::set<int> s;
  for (int i = 1; i <= 100; i++) {
    for (int j = i + 1; j <= 100; j++) {
      s.insert(j * j - i * i);
    }
  }
  // for (int i : s) {
  //   std::cerr << i << ' ';
  //   if (i % 4 == 0) {
  //     std::cerr << '\n';
  //   }
  // }

  while (t--) {
    solve();
  }

  return 0;
}