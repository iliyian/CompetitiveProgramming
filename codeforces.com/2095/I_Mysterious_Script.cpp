#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  std::string cur;
  int x = 0, y = 0;
  std::map<std::string, int> mp = {
    {"la", 0},
     {"le", 1},
     {"lon", 2},
     {"sha", 3},
    {"she", 4},
     {"shon", 5},
     {"ta", 6},
     {"te", 7},
    {"ton", 8},
  };
  std::string to[] = {"la", "le", "lon", "sha", "she", "shon", "ta", "te", "ton"};
  for (int i = 0; i < a.size() - 1; i++) {
    cur.push_back(a[i]);
    if (mp.count(cur)) {
      x = x * 9 + mp[cur];
      cur.clear();
    }
  }
  for (int i = 0; i < b.size() - 1; i++) {
    cur.push_back(b[i]);
    if (mp.count(cur)) {
      y = y * 9 + mp[cur];
      cur.clear();
    }
  }
  // std::cerr << x << ' ' << y << '\n';
  int z = x + y;
  std::vector<std::string> ans;
  while (z) {
    ans.push_back((to[z % 9]));
    z /= 9;
  }
  for (auto &s : ans | std::views::reverse) {
    std::cout << s;
  }
  std::cout << "s\n";
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