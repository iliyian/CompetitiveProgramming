#include <bits/stdc++.h>
#define int long long

int get(int a, int b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::array<int, 3>> f(n + 1, {0, 0, 0});
  for (int i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0] + get(a[i], f[i - 1][0]);
    // if (i > 1) {
      f[i][1] = std::max(f[i - 1][0], f[i - 1][1]);
    // }
    if (i > 1) {
      f[i][2] = std::max(f[i - 1][1] + get(a[i], f[i - 1][1]), f[i - 1][2] + get(a[i], f[i - 1][2]));
    }
  }
  std::cout << f[n][2] << '\n';
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