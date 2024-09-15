#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("A3.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<std::pair<int, int>> a(n + 1);
  a[1] = {0, -1};
  for (int i = 2; i <= n; i++) {
    a[i].first = a[i - 1].first + (str[i - 1] == '(' ? 1 : -1);
    a[i].second = -i;
  }
  std::sort(a.begin() + 1, a.end());
  std::string ans(n + 1, '#');
  for (int i = 1; i <= n; i++) {
    ans[i] = str[-a[i].second];
  }
  std::cout << ans.substr(1) << '\n';
  return 0;
}