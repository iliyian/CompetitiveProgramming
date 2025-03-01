#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int s1(int x) {
  return x * (x + 1) / 2 % mod;
}

int s2(int x) {
  return x * (x + 1) * (2 * x + 1) / 6 % mod;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0;
  if (k > n) {
    ans += n * ((k - n) % mod) % mod;
    ans %= mod;
    k = n;
  }
  for (int l = 2, r; l <= k; l = r + 1) {
    if (l * l <= n) {
      r = l;
      std::vector<int> a;
      for (int x = n; x; x /= l) {
        a.push_back(x % l);
      }
      int x = 0;
      for (int i : a) {
        x = x * l + i;
        x %= mod;
      }
      ans += x;
      ans %= mod;
    } else { // 仅有两位
      r = std::min(k, n / (n / l));
      ans += n * (s1(r) - s1(l - 1) + mod) % mod;
      ans %= mod;
      ans -= (n / l) * (s2(r) - s2(l - 1) + mod) % mod;
      ans = (ans + mod) % mod;
      ans += (n / l) * (r - l + 1) % mod;
      ans %= mod;
    }
  }
  std::cout << ans << '\n';
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