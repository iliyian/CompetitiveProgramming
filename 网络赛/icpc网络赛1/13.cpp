#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::set<std::string>> s(26);
  for (int i = 1; i <= n; i++) {
    std::string team, result;
    char p;
    std::cin >> team >> p >> result;
    if (result == "accepted") {
      s[p - 'A'].insert(team);
    }
  }
  int mx = 0;
  for (auto &x : s) {
    mx = std::max<int>(mx, x.size());
  }
  for (int i = 0; i < 26; i++) {
    if (s[i].size() == mx) {
      std::cout << char(i + 'A') << '\n';
      return;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}