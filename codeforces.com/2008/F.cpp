#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

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

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += a[i] * a[i - 1] % mod;
    ans %= mod;
    a[i] += a[i - 1] % mod;
    a[i] %= mod;
  }
  std::cout << ans * inv(n * (n - 1) / 2 % mod) % mod << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}