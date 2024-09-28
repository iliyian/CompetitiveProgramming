#include <bits/stdc++.h>

int main() {
  int x, y, z, a, b, c;
  std::cin >> x >> y >> z >> a >> b >> c;
  int t = std::min(b, y);
  b -= t, y -= t;
  if (y) {
    if (a < y) {
      std::cout << "NO\n";
      return 0;
    }
    a -= y;
    y = 0;
  }
  if (a < x) {
    std::cout << "NO\n";
    return 0;
  }
  a -= x;
  x = 0;
  if (a + c + b < z) {
    std::cout << "NO\n";
    return 0;
  }
  std::cout << "YES\n";
  return 0;
}
/*
7 3 9
7 8 4
*/