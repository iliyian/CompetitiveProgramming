#include <bits/stdc++.h>

signed main() {
  int a[10];
  for (int i = 0; i < 10; i++) {
    std::cin >> a[i];
  }
  int x;
  std::cin >> x;
  for (int i = 0; i < 10; i++) {
    std::cout << a[i] + x << ' ';
  }
  return 0;
}