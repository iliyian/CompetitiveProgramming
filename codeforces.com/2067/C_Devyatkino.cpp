#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int ans = 7;
  // int d = (str[i] - '0' + 3) % 10; // 下降
  int j = str.size() - 2;
  while (j >= 1 && str[j] == '0') j--;
  for (int i = str.size() - 2; i >= 0; i--) {
    int d = (7 - (str[i] - '0') + 10) % 10; // 上升
    if (d > str.back() - '0' && i == j) {
      d++;
    }
    ans = std::min(ans, d);
  }
  // std::cerr << ans << '\n';
  ans = std::min<int>(ans, (str.back() - '0' + 3) % 10);
  // std::cerr << j << ' ' << ans << '\n';
  // std::cerr << ans << '\n';
  if (str[j] == '8') {
    ans = std::min<int>(ans, str.back() - '0' + (str[j] - '0' + 3) % 10);
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