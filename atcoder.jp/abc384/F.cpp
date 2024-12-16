#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::map<int, int>> f(26); // 33554432 = 2^25
  std::vector<std::map<int, int>> cnt(26);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 25; j >= 0; j--) {
      if (a[i] % (1 << j) == 0) {
        ans += (a[i] / (1 << j));
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int cntt = i - 1;
    for (int j = 25; j >= 0; j--) {
      if (cntt <= 0) break;
      int t = - (a[i] % (1 << j));
      if (t < 0) t += (1 << j);
      cntt -= cnt[j][t];
      ans += f[j][t];
      // assert(cntt >= 0);
    }
    for (int j = 0; j <= 25; j++) {
      int t = a[i] % (1 << j);
      f[j][t] += a[i];
      cnt[j][t]++;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
