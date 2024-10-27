#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937 rd(std::random_device{}());

signed main() {
  freopen("E.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n = 3e5, m = 3e5;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << std::uniform_int_distribution<>{(int)-1e9, (int)1e9}(rd) << ' ';
  }
  std::cout << '\n';
}