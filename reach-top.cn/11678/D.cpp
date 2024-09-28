#include <bits/stdc++.h>

int main() {
  int a, b;
  std::cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    ans += (i % 4 == 0 && i % 100) || i % 400 == 0;
  }
  std::cout << ans << '\n';
  return 0;
 }