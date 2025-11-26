#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  std::ranges::reverse(str);
  str = '#' + str;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(200, LLONG_MAX / 2));
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 5, 10, 50, 100, 500, 1000};
  int c[18] {};
  for (int i = 0; i < 17; i++) {
    std::cin >> c[i];
  }
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < 200; s++) {
      for (int j = 0; j < 17; j++) {
        int val = a[j];
        if ((s + val) % 10 == str[i + 1] - '0') {
          f[i + 1][(s + val) / 10] = std::min(f[i + 1][(s + val) / 10], f[i][s] + c[j]);
        }
      }
    }
  }
  int ans = f[n][0];
  std::ranges::reverse(str);
  for (int i = 1; i <= std::min(n, 3ll); i++) {
    int j = std::stoll(str.substr(0, i));
    if (j < 200) {
      ans = std::min(ans, f[n - i][std::stoll(str.substr(0, i))]);
    }
  }
  std::cout << ans << '\n';
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