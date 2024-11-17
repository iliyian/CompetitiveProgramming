#include <bits/stdc++.h>
#define int long long

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  int ans = 0;
  auto check = [&](int dep) {
    int x = dep, y = dep;
    std::string str = "?";
    int len = (n - (dep - 1) * 2) * 2 + (m - (dep - 1) * 2) * 2 - 4;
    // std::cout << len << '\n';
    for (int d = 0; str.size() < len + 3; d = (d + 1) % 4) {
      str.pop_back();
      while (str.size() < len + 3 && x >= dep && x <= n - dep + 1 && y >= dep && y <= m - dep + 1) {
        str.push_back(a[x][y]);
        x += dx[d], y += dy[d];
      }
      x -= dx[d], y -= dy[d];
    }
    for (int i = 0; i + 3 < str.size(); i++) {
      ans += str.substr(i, 4) == "1543";
    }
    // std::cout << str << '\n';
  };
  int x = std::min((n + 1) / 2, (m + 1) / 2);
  for (int i = 1; i <= x; i++) {
    check(i);
  }
  std::cout << ans << '\n';
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