#include <bits/stdc++.h>

std::mt19937 rd(std::random_device{}());

int main() {
  freopen("E.in", "w", stdout);
  int n = 1e5, m = 1e5;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % 2 << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= m; i++) {
    int op = rd() % 4, l = rd() % n, r = rd() % n;
    if (l > r) std::swap(l, r);
    std::cout << op << ' ' << l << ' ' << r << '\n';
  }
  return 0;
}