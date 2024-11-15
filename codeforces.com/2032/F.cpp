// date: 2024-11-14 22:54:47
// tag: nim游戏，反nim游戏，博弈论，计数dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;
constexpr int N = 1e6;

std::vector<int> p(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int prv = 1, m = 1, x = 0;
  while (m <= n && a[m] == 1) {
    x ^= a[m];
    if (m % 2 == 0) {
      prv = prv + p[m - 1];
      prv %= mod;
    }
    m++;
  }
  if (m == n + 1) {
    std::cout << (n & 1 ? p[n - 1] : 0) << '\n';
    return;
  }
  int ans = 0;
  for (int i = m; i <= n; i++) {
    x ^= a[i];
    if (x == 1) {
      ans = ans + p[m - 1] * p[std::max(0ll, n - i - 1)] % mod;
      ans %= mod;
    } else if (x > 1) {
      ans = ans + prv * p[std::max(0ll, n - i - 1)] % mod;
      ans %= mod;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    p[i] = p[i - 1] * 2 % mod;
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}