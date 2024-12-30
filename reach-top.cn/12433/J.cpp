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
  for (int n = 1; n <= 10; n++) {
    for (int i = 1; i <= 10 - n; i++) {
      std::cout << ' ';
    }
    for (int i = 1; i <= n * 2 - 1; i++) {
      std::cout << char('A' + i - 1);
    }
    std::cout << '\n';
  }
  return 0;
}