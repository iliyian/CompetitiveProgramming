// date: 2024-08-15 09:19:44
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> a(n + 1, std::vector<char>(m + 1));

  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  auto check = [&](int k, int x, int y) {
    if (a[x][y]) return false;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (in(xx, yy) && a[xx][yy] == k) {
        return false;
      }
    }
    return true;
  };

  auto work = [&](int k, int x, int y) {
    int len = 1;
    if (!check(k, x, y)) return false;
    while (true) {
      int xx = x + len - 1, yy = y + len - 1;
      if (!in(x, yy) || !in(xx, y) || !check(k, x, yy) || !check(k, xx, y)) {
        len--;
        break;
      }
      for (int i = 1; i < len; i++) {
        for (int j = 'A'; j < k; j++) {
          if (check(j, x, y + i)) {
            len--;
            goto end;
          }
        }
      }
      len++;
    }
    end:;
    for (int i = x; i <= x + len - 1; i++) {
      for (int j = y; j <= y + len - 1; j++) {
        a[i][j] = k;
      }
    }
    return true;
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j]) {
        for (char k = 'A'; k <= 'Z'; k++) {
          if (work(k, i, j)) {
            break;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << a[i][j];
    }
    std::cout << '\n';
  }

  return 0;
}