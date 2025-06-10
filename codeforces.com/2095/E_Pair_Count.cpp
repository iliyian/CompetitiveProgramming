#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b, const int &p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}

int inv(int x, const int &p) {
  return qpow(x, p - 2, p);
}

void solve() {
  int n, p, k;
  std::cin >> n >> p >> k;
  std::map<int, int> mp;
  int ans = 0, cnt = 0;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (k == 0) {
      int x = a[i] * a[i] % p * a[i] % p;
      if (x == 0) {
        ans += i - 1;
        cnt++;
      } else {
        ans += cnt;
      }
    } else {
      ans += mp[a[i] * a[i] % p * a[i] % p];
      mp[inv(a[i] * a[i] % p * a[i] % p, p) * k % p]++;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}