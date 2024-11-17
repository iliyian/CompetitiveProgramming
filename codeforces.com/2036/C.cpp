#include <bits/stdc++.h>
#define int long long

void solve() {
  int q;
  std::string str;
  std::cin >> str >> q;
  int n = str.size();
  str = '#' + str;
  std::set<int> s;
  for (int i = 1; i + 3 <= n; i++) {
    if (str.substr(i, 4) == "1100") {
      s.insert(i);
    }
  }
  while (q--) {
    int x, v;
    std::cin >> x >> v;
    str[x] = v + '0';
    for (int i = std::max<int>(1, x - 3); i <= x && i + 3 <= n; i++) {
      if (s.count(i)) {
        s.erase(i);
      }
      if (str.substr(i, 4) == "1100") {
        s.insert(i);
      }
    }
    std::cout << (s.empty() ? "NO" : "YES") << '\n';
  }
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