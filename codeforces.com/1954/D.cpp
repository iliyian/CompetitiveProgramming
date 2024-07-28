// date: 2024-07-28 13:14:12
// tag: 背包

#include <bits/stdc++.h>
#define int long long
// using namespace std;

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

int inv(int a) {
  return qpow(a, mod - 2);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int ans = 0;
  std::vector<int> f(s[n] + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= a[i]; j++) {
      ans += f[j] * a[i] % mod;
      ans %= mod;
    }
    for (int j = a[i] + 1; j <= s[i - 1]; j++) {
      ans += f[j] * ((j + a[i] + 1) / 2) % mod;
      ans %= mod;
    }
    for (int j = s[i]; j >= a[i]; j--) {
      f[j] += f[j - a[i]];
      f[j] %= mod;
    }
  }
  std::cout << ans << '\n';

  return 0;
}