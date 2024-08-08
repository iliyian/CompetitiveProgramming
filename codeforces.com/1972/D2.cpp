// date: 2024-08-06 16:14:25
// tag: gcd，暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  for (int a = 1; a * a <= n; a++) {
    for (int b = 1; b * b <= m; b++) {
      int g = std::gcd(a, b), sum = a + b;
      if (g == 1) {
        ans += std::min(n / a, m / b) / (a + b);
      }
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}