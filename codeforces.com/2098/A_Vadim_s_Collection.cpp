#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  std::multiset<int> s;
  for (int i = 0; i < str.size(); i++) {
    s.insert(str[i]);
  }
  bool f = false;
  for (int i = 0; i < 10; i++) {
    auto p = s.lower_bound(9 - i + '0');
    if (p != s.end()) {
      std::cout << char(*p);
      s.erase(p);
    }
  }
  std::cout << '\n';
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