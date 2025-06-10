#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int cur = 0;
  std::set<int> s;
  std::vector<int> ans(n + 2);
  s.insert(cur);
  ans[1] = 0;
  int mn = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '<') {
      cur--;
      while (s.count(cur)) cur--;
    } else {
      cur++;
      while (s.count(cur)) cur++;
    }
    s.insert(cur);
    mn = std::min(mn, cur);
    ans[i + 2] = cur;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] - mn + 1 << " \n"[i == n];
    // std::cout << ans[i] << " \n"[i == n];
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