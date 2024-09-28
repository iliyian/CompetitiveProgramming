#include <bits/stdc++.h>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  int x = c - a;
  if (d < b) x--, d += 60;
  std::cout << x * 60 + d - b << '\n';
  return 0;
 }