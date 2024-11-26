#include <bits/stdc++.h>
#define int long long

std::set<std::string> s;

void solve() {
  int n;
  std::string str;
  std::cin >> n;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> str;
    if (str.find("bie") != str.npos && !s.count(str)) {
      std::cout << str << '\n';
      f = true;
      s.insert(str);
    }
  }
  if (!f) {
    std::cout << "Time to play Genshin Impact, Teacher Rice!\n";
  }
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}