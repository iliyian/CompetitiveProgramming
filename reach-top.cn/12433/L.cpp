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
  // std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string a, b;
  std::cin >> a >> b;
  int _a = 0, _b = 0;
  for (char ch : a) {
    if (isdigit(ch)) {
      _a = _a * 10 + ch - '0';
    }
  }
  for (char ch : b) {
    if (isdigit(ch)) {
      _b = _b * 10 + ch - '0';
    }
  }
  std::string x = std::to_string(_a * _b);
  if (x.size() == 11 && x.front() == '1') {
    std::cout << x << '\n';
    return 0;
  }
  std::cout << "Fail\n";
  return 0;
}