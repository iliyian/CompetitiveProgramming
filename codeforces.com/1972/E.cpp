// date: 2024-08-07 09:48:37
// tag: 树状数组，组合数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 998244353;

std::vector<int> inv(25);

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int t = 1;
    // 如果d初始为k，记得d也要取模，大概
    for (int j = i + (i & -i), d = 1; j <= n; j += j & -j, d++) {
      t = (k + d - 1) % mod * t % mod * inv[d] % mod;
      a[j] -= t * a[i] % mod;
      a[j] = (a[j] % mod + mod) % mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  inv[1] = 1;
  for (int i = 2; i <= 24; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}