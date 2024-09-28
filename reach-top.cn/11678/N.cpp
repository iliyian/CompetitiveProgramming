#include <bits/stdc++.h>
#define int long long

signed main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << char('A' + (i + j - 2) % 26);
    }
    std::cout << '\n';
  }
  
  return 0;
}