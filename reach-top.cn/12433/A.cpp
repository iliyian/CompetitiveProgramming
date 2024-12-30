#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::cout << gcd(n, m) << ' ' << n * m / gcd(n, m) << '\n';
  return 0;
}