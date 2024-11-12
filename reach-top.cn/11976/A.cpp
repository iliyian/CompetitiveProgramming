#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << gcd(std::abs(a - b), std::abs(c - d)) << '\n';
}

signed main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}