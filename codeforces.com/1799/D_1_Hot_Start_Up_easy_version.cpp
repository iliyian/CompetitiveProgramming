// date: 2025-04-23 21:54:51
// tag: 独立过难题的感觉是很爽的。常见的根据性质压缩掉一个状态的dp。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> cold(k + 1), hot(k + 1);
  // std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1, LLONG_MAX / 3));
  std::vector<int> f(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> cold[i];
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> hot[i];
  }
  // f[1][0] = cold[a[1]];
  f[0] = cold[a[1]];
  int add = 0;
  for (int i = 2; i <= n; i++) {
    add += (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]);
    // for (int j = 0; j <= k; j++) {
    //   if (f[i - 1][j] == LLONG_MAX / 3) continue;
    //   f[i][j] = f[i - 1][j] + (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]);
    // }
    f[a[i - 1]] = std::min(f[a[i] - 1], );
    for (int j = 0; j <= k; j++) {
      // if (!f[i - 1][j]) continue;
      f[i][a[i - 1]] = std::min(f[i][a[i - 1]], (j == a[i] ? hot[a[i]] : cold[a[i]]) + f[i - 1][j]);
    }
  }
  std::cout << *std::min_element(f[n].begin(), f[n].end()) << '\n';
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