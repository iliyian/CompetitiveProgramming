#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  int ans = 0;
  for (int i = 0, j = 0; i < n; i = j + 1) {
    j = std::max(j, i);
    while (j + 1 < n && (str[j + 1] != str[j] && (j == i || str[j + 1] != str[j - 1]))) j++;
    ans = std::max(ans, j - i + 1 + (i >= 1 && str[i] != str[i - 1] && (i + 1 > j || str[i - 1] != str[i + 1])));
  }
  std::cout << ans << '\n';
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