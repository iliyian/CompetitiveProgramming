#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans++;
    }
  }
  std::cout << ans << '\n';
  return 0;
 }