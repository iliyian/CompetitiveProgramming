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
  int a1 = 0, a2 = 0;
  for (int i = 1; i <= 9; i++) {
    int x;
    std::cin >> x;
    if (i == 1 || i == 5 || i == 9) a1 += x;
    if (i == 3 || i == 5 || i == 7) a2 += x;
  }
  std::cout << a1 << ' ' << a2 << '\n';
  return 0;
}