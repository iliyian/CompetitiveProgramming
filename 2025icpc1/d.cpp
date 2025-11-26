#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n = 5000, m = 10000, w = 1e9;
  std::cout << n << ' ' << m << '\n';
  for (int i = 2; i <= n; i++) {
    std::cout << rd() % (i - 1) + 1 << ' ' << i << ' ' << rd() % w + 1 << '\n';
  }
  for (int i = 1; i <= m; i++) {
    int x = rd() % n + 1, y = rd() % n + 1;
    while (x == y) {
      x = rd() % n + 1, y = rd() % n + 1;
    }
    if (x > y) std::swap(x, y);
    std::cout << x << ' ' << y << '\n';
  }

  return 0;
}