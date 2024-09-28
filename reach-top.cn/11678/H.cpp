#include <bits/stdc++.h>

int main() {
  int ans = 0, n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    ans += (1 + i) * i / 2;
  }
  std::cout << ans << '\n';
  return 0;
 }