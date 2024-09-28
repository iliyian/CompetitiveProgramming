#include <bits/stdc++.h>
// using namespace std;

inline double f(double x) {
  if (x < 0) return -x;
  return f(x - f(x - 1)) / 2;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::cout << std::setprecision(20);
  for (int i = 0; i <= 3; i++) {
    std::cout << f(i) << '\n';
  }

  return 0;
}