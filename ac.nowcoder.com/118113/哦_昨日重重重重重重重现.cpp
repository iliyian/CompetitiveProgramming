#include <bits/stdc++.h>
#define int long long

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

std::string URDL = "URDL";

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  int sx = 0, sy = 0;
  std::set<std::pair<int, int>> st;
  st.insert({0, 0});
  for (int i = 0; i < n; i++) {
    int d = URDL.find(s[i]);
    sx += dx[d], sy += dy[d];
    st.insert({sx, sy});
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (!st.count({x, y})) {
      std::cout << 0 << '\n';
    } else {
      std::cout << 1 << '\n';
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