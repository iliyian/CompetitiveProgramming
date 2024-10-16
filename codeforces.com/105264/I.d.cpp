#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

signed main() {
  freopen("I.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 10000;
  std::cout << t << '\n';
  for (int i = 1; i <= t; i++) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  return 0;
}