#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int fac(int x) {if (!x) return 1; return x * fac(x - 1);}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  double ans = 1;
  for (int i = 1; i <= n; i++) {
    ans += 1.0 / fac(i);
  }
  std::cout << std::fixed << std::setprecision(6) << ans << '\n';
  return 0;
}