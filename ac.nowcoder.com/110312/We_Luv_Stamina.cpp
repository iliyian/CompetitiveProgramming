#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    if ((a[i][1] == '1' || a[i][2] == '1') && (a[i + 1][1] == '1' || a[i + 1][2] == '1')) {
      a[i][1] = a[i][2] = '0';
      a[i + 1][1] = a[i + 1][2] = '1';
    }
    if ((a[i][3] == '1' || a[i][4] == '1') && (a[i + 1][3] == '1' || a[i + 1][4] == '1')) {
      a[i][3] = a[i][4] = '0';
      a[i + 1][3] = a[i + 1][4] = '1';
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i].substr(1, 4) << '\n';
  }
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