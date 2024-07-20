// date: 2024-07-19 10:22:32
// tag: dp，位运算

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(64));
  for (int i = 1; i <= n; i++) {
    f[i][a[i]] = 1;
  }
  for (int S = 63; S >= 0; S--) {
    for (int i = 1; i <= n; i++) {
      f[i][S & a[i]] += f[i - 1][S];
      f[i][S & a[i]] %= mod;

      f[i][S] += f[i - 1][S];
      f[i][S] %= mod;
    }
  }
  int ans = 0;
  for (int S = 63; S >= 0; S--) {
    if (__builtin_popcount(S) == k) {
      ans += f[n][S];
      ans %= mod;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}