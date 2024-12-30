#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int fac(int x) {if (!x) return 1; return x * fac(x - 1);}
bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int a = 0, b = 1, c = 10;
  while (c) {
    if (isprime(b)) {
      std::cout << std::setw(8) << std::left << b;
      c--;
      if (c == 5) {
        std::cout << '\n';
      }
    }
    int t = a + b;
    a = b;
    b = t;
  }
  std::cout << '\n';
  return 0;
}