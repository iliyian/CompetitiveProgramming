#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int fac(int x) {if (!x) return 1; return x * fac(x - 1);}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  double x, S = 0;
  double term = 1;
  int n = 1;
  std::cin >> x;
  int fac = 1;
  while (term >= 1e-5 || term <= -1e-5) {
    S += term;
    term *= x * x / (n * 2) / (n * 2 - 1) * (-1);
    n++;
  }
  std::cout << "S=" << S << std::endl;
  // std::cout << n << '\n';
  return 0;
}