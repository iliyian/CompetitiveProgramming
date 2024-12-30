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
  int n;
  std::string str;
  std::cin >> n >> str;
  for (int i = 0; i < str.size(); i++) {
    std::cout << char((str[i] - 'a' + n + 26) % 26 + 'a');
  }
  return 0;
}