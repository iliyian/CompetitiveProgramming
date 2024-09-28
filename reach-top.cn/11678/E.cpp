#include <bits/stdc++.h>

int main() {
  int a, b;
  std::cin >> a >> b;
  int ans[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  std::cout << (((a % 4 == 0 && a % 100) || a % 400 == 0) && b == 2 ? 29 : ans[b]) << '\n';
  return 0;
 }