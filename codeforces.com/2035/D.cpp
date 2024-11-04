#include <bits/stdc++.h>
#define int long long

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

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 1, cnt = 0, mx = 1, sum = 0;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    if (!f && a[i] > mx) {
      a[i] = mx;
    }
    while (a[i] % 2 == 0) cnt++;
    sum += a[i];
    if (cnt >= 31) f = true;
    mx = mx * qpow(2, cnt) % mod;
    int ans = mx * qpow(2, cnt) + sum - mx;
    std::cout << ans % mod << ' ';
  }
  std::cout << '\n';
}

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}