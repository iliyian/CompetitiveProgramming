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
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  std::sort(a.begin(), a.end());
  for (auto i : a) {
    std::cout << std::setw(4) << i;
  }
  return 0;
}