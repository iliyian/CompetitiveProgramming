// date: 2025-01-22 18:52:54
// tag: 思维

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

constexpr int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
constexpr int inv(int x) {return qpow(x, mod - 2);}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), b(n + 1), ra(n + 1), rb(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ra[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    rb[i] = b[i];
  }
  std::sort(a.begin() + 1, a.end());
  std::sort(b.begin() + 1, b.end());
  int ans = 1;
  auto mul = [&](int x) {
    ans = ans * std::min(a[x], b[x]) % mod;
  };
  auto div = [&](int x) {
    ans = ans * inv(std::min(a[x], b[x])) % mod;
  };
  for (int i = 1; i <= n; i++) {
    mul(i);
  }
  std::cout << ans << ' ';
  for (int i = 1; i <= q; i++) {
    int o, x;
    std::cin >> o >> x;
    if (o == 1) {
      auto p = std::upper_bound(a.begin() + 1, a.end(), ra[x]) - a.begin() - 1;
      div(p);
      a[p]++;
      ra[x]++;
      mul(p);
    } else {
      auto p = std::upper_bound(b.begin() + 1, b.end(), rb[x]) - b.begin() - 1;
      div(p);
      b[p]++;
      rb[x]++;
      mul(p);
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}