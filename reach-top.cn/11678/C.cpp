#include <bits/stdc++.h>

int main() {
  int a, b, c;
  char d;
  std::cin >> a >> b >> c >> d;
  std::cout << ((a + (d == 'P' ? 12 : 0)) * 3600) + b * 60 + c << '\n';
 }