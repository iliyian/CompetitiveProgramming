#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(200));
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 5, 10, 50, 100, 500, 1000, 0};
  int c[18];
  for (int i = 0; i < 17; i++) {
    std::cin >> c[i];
  }
  c[17] = 0;
  for (int i = n; i >= 1; i--) {
    for (int s = 0; s < 200; s++) {
      for (int j = 0; j < 18; j++) {
        int v = str[i] - '0' + s * 10 - a[j];
        if (v < 0 || v >= 200) continue;
        f[i][s] += f[i - 1][v] + c[j];
      }
    }
  }
  std::cout << f[1][0] << '\n';
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