#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
std::string dir = "URDL";
int get(char c) {
  if (c == 'U') return 0;
  if (c == 'R') return 1;
  if (c == 'D') return 2;
  if (c == 'L') return 3;
}

void solve() {
  int h, w, n;
  std::cin >> h >> w >> n;
  std::string str;
  std::cin >> str;
  std::vector<std::string> a(h + 1);
  for (int i = 1; i <= h; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
  };
  auto move = [&](int &sx, int &sy) -> bool {
    for (int i = 0; i < n; i++) {
      int d = get(str[i]);
      int xx = sx + dx[d], yy = sy + dy[d];
      if (in(xx, yy) && a[xx][yy] == '.') {
        sx = xx, sy = yy;
      } else {
        return false;
      }
    }
    return true;
  };
  std::set<int> s;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (a[i][j] == '.') {
        int x = i, y = j;
        auto f = move(x, y);
        if (f) {
          s.insert(x * w + j);
        }
      }
    }
  }
  std::cout << s.size() << '\n';
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