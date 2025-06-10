#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, r, c;
  std::cin >> n >> r >> c;
  std::string str;
  std::cin >> str;
  std::string nesw = "NESW";
  std::map<int, std::set<int>> mx;
  int x = 0, y = 0;
  mx[0].insert(0);
  for (int i = 0; i < str.size(); i++) {
    int d = nesw.find(str[i]);
    x += dx[d], y += dy[d];
    if (mx[x - r].count(y - c)) {
      std::cout << 1;
    } else {
      std::cout << 0;
    }
    mx[x].insert(y);
  }
  std::cout << '\n';
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