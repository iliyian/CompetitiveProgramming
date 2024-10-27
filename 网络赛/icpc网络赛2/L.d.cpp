#include <bits/stdc++.h>

int main() {
  freopen("L.in", "w", stdout);
  int n =1e6, T = 1e9;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << T - i + 1 << '\n';
  }
  return 0;
}