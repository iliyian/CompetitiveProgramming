// date: 2024-08-07 15:44:23
// tag: 集合，期望dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

double qpow(double a, int b) {
  double ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n, m;
  std::cin >> m >> n;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += i * (qpow(double(i) / m, n) - qpow((double(i) - 1) / m, n));
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';

  return 0;
}