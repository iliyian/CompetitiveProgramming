#include <bits/stdc++.h>
#define int long long

signed main() {
  int n;
  std::cin >> n;
  int t = 1, cur = 0;
  for (int i = 1; t <= n; i++) {
    std::cout << char('A' + cur++);
    cur %= 26;
    if (i % t == 0) {
      i = 0;
      t++;
      std::cout << '\n';
    }
  }
  return 0;
}