#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  k = std::min(k, n);
  std::vector<std::array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0];
    a[i][1] = i;
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1, LLONG_MAX / 3));
  std::vector<std::vector<int>> prv(n + 1, std::vector<int>(k + 1));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j >= 1; j--) {
      sum += (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]);
      for (int l = 1; l <= std::min({k, i, j}); l++) {
        if (f[i][l] > f[j - 1][l - 1] + sum) {
          f[i][l] = std::min(f[i][l], f[j - 1][l - 1] + sum);
          prv[i][l] = j - 1;
        }
      }
    }
  }
  int x = n, y = n;
  std::vector<int> ans(n + 1);
  while (k) {
    while (y > prv[x][k]) {
      ans[a[y--][1]] = x;
    }
    x = prv[x][k--];
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[ans[i]][0] << " \n"[i == n];
  }
  // std::cout << f[n][k] << '\n';
  // std::cerr << f[2][1] << '\n';
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