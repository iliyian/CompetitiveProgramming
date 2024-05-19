#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("J.in", "r", stdin);
  freopen("J.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<char>> a(n + 1, vector<char>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  auto solve = [&](auto self, int x, int y, int len) -> void {
    if (len == 1) {
      cout << a[x][y];
      return;
    }
    self(self, x, y, len / 2);
    self(self, x, y + len / 2, len / 2);
    self(self, x + len / 2, y, len / 2);
    self(self, x + len / 2, y + len / 2, len / 2);
  };
  solve(solve, 1, 1, n);

  return 0;
}