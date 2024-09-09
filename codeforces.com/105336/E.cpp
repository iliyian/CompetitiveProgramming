#include <bits/stdc++.h>
#define int long long
using namespace std;

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

signed main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(m + 1);
  p[0] = 1;
  for (int i = 1; i <= m; i++) {
    p[i] = p[i - 1] * 26 % mod;
  }
  int mx = 1;
  for (int i = 1, t = 26; i <= m; i++) {
    mx += t > n ? n : qpow(26, i);
    // mx += std::min(qpow(26, i), n);
    mx %= mod;
    if (t <= n) t *= 26;
  }
  std::cout << mx << ' ';
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    int t = (-inv(p[i]) + mod) % mod;
    t = qpow((t + 1) % mod, n);
    t = ((1 - t) % mod + mod) % mod;
    ans += p[i] * t % mod;
    ans %= mod;
  }
  std::cout << ans << '\n';
  return 0;
}