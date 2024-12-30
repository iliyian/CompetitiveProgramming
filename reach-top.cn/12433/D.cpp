#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int fac(int x) {if (!x) return 1; return x * fac(x - 1);}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, n;
  std::cin >> a >> b >> n;
  a %= b;
  int c = 0;
  while (n--) {
    a *= 10;
    c = a / b;
    a %= b;
  }
  std::cout << c << '\n';
  return 0;
}