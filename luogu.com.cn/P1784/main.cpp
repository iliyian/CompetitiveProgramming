// date: 2024-09-12 20:13:24
// tag: 暴搜

#include <bits/stdc++.h>
#define int long long

std::vector<std::vector<int>> a(9, std::vector<int>(9));
// std::vector<std::bitset<9>> can(9);

std::vector<std::bitset<10>> r(9), c(9), b(9);

bool check(int x, int y, int num) {
  if (r[x][num] || c[y][num] || b[x / 3 * 3 + y / 3][num]) return false;
  return true;
}

int cnt = 0;

void put(int i, int j, int num, bool val) {
  cnt += (val ? 1 : -1);
  r[i][num] = val;
  c[j][num] = val;
  b[i / 3 * 3 + j / 3][num] = val;
}

void dfs(int x, int y) {
  if (x == 9) return;
  if (y == 9) return dfs(x + 1, 0);
  if (cnt == 81) return;
  if (a[x][y]) return dfs(x, y + 1);
  for (int i = 1; i <= 9; i++) {
    if (check(x, y, i)) {
      a[x][y] = i;
      put(x, y, a[x][y], 1);
      dfs(x, y + 1);
      if (cnt == 81) {
        return;
      }
      put(x, y, a[x][y], 0);
      a[x][y] = 0;
    }
  }
}

signed main() {
  freopen("main.in", "r", stdin);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cin >> a[i][j];
      if (a[i][j]) {
        put(i, j, a[i][j], 1);
      }
    }
  }
  dfs(0, 0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      std::cout << a[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}