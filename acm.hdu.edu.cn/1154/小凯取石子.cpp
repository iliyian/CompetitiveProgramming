#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

int cof[] = {0, 0, 0, 2, 1, 0, 1, 0, 3, 2};

std::map<std::pair<int, bool>, double> mp;
double work(int n, bool f) {
  if (!n) return 0;
  if (n < 0) return 1;
  if (mp.count({n, f})) return mp[{n, f}];
  if (f) {
    return 0.5 * (1 - work(n - 1, f ^ 1) + 1 - work(n - 4, f ^ 1));
  }
  return mp[{n, f}] = 1.0 - std::min(work(n - 1, f ^ 1), work(n - 4, f ^ 1));
}

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << inv(2) << '\n';
    return;
  }
  if (n % 10 == 0 || n % 10 == 2 || n % 10 == 5 || n % 10 == 7) {
    std::cout << 1 << '\n';
    return;
  }
  if (n < 10) {
    std::cout << (1 - inv(qpow(2, cof[n])) % mod + mod) % mod << '\n';
    return;
  }
  int t = n / 10;
  int ans = (1 - qpow(inv(2), t * 2 % mod + cof[n % 10]) % mod + mod) % mod;
  std::cout << ans << '\n'; 
  // auto ans = work(n, 1);
  // std::cout << n << ' ' << std::fixed << std::setprecision(20) << 1.0 / work(n, 1) << '\n';
  // std::cout << n << ' ' << 1.0 - ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}