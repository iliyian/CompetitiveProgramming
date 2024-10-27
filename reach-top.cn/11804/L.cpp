#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  bool f = false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) n /= i, cnt++;
      if (f) std::cout << "* ";
      std::cout << i;
      if (cnt > 1) {
        std::cout << '^' << cnt;
      }
      std::cout << ' ';
      f = true;
    }
  }
  if (n > 1) {
    if (f) std::cout << "* ";
    std::cout << n;
  }
  return 0;
}