#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n = 1e6;
  std::cout << n << '\n';
  std::vector<std::array<int, 3>> a(n);
  int h;
  char s;
  for (int i = 0; i < n; i++) {
    std::cout << rd() % (int)1e9 << ' ' << (rd() & 1 ? 'm' : 'f') << '\n';
  }
  return 0;
}