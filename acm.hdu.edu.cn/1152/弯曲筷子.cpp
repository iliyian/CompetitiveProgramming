// date: 2025-03-25 14:07:54
// tag: array<int, 2>在vector里面初始化时，记得多声明几个数值，哎

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0];
  }
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    a[x][1] = 1;
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<std::array<int, 2>> f(n + 1, std::array<int, 2>{LLONG_MAX / 3});
  f[1][0] = 0;
  // f[2][1] = (a[2][0] - a[1][0]) * (a[2][0] - a[1][0]);
  // if (!a[2][1])
  //   f[2][0] = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1][1]) {
      f[i][0] = f[i - 1][1];
      // 前一个必须选，则前一个必须已经选，因为当前不选且后面更劣所以必须在这之前
      f[i][1] = f[i - 1][0] + (a[i][0] - a[i - 1][0]) * (a[i][0] - a[i - 1][0]);
      // 选了则必须只能和前一个，后面还不存在
    } else {
      f[i][0] = std::min(f[i - 1][1], f[i - 1][0]);
      f[i][1] = std::min(
          {f[i - 1][0] + (a[i][0] - a[i - 1][0]) * (a[i][0] - a[i - 1][0]),
           f[i - 2][0] + (a[i][0] - a[i - 2][0]) * (a[i][0] - a[i - 2][0])});
    }
  }
  if (a[n][1]) {
    std::cout << f[n][1] << '\n';
  } else {
    std::cout << std::min(f[n][0], f[n][1]) << '\n';
  }
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