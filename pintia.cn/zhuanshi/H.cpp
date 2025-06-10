#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  // std::map<int, int> mp;
  std::map<std::string, std::string> mp;
  for (int i = 1; i <= n; i++) {
    // int x, y;
    std::string x, y;
    std::cin >> x >> y;
    mp[x] = y;
    // mp[y] = x;
  }
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    // int x, y;
    std::string x, y;
    std::cin >> x >> y;
    if (mp[x] == y || mp[y] == x) {
      std::cout << "(~_~)\n";
    } else {
      std::cout << "o(@O@)o\n";
    }
  }
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