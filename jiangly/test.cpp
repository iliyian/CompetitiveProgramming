#include <bits/stdc++.h>
#define int long long

void solve() {
  int i;
  while (std::cin >> i) // 循环条件
  {
      if (i >= 1 && i <= 3)
          std::cout << '*';
      else std::cout << i;
  }
  std::cout << std::endl; 
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}