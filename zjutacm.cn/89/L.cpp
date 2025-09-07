#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1);
  std::vector<std::array<int, 2>> f(n + 1, {LLONG_MIN / 3, LLONG_MIN / 3});
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= std::max(0ll, i - 40); j--) {
      bool flag = true;
      for (int k = j + 1; k <= i; k++) {
        if (a[k] < s[k - 1] - s[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        f[i][1] = std::max(f[i][1], f[j][0] + s[i] - s[j]);
      }
      f[i][0] = std::max({f[i][0], f[j][0], f[j][1]});
    }
  }
  std::cout << std::max(f[n][1], f[n][0]) % 998244353 << '\n';
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