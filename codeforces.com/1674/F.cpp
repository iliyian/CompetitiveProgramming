// date: 2024-05-02 15:14:54
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<char>> a(n, vector<char>(m));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      cnt += a[i][j] == '*';
    }
  }
  int in = 0;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (j * n + i > cnt - 1) {
        break;
      }
      in += a[i][j] == '*';
    }
  }
  cerr << cnt - in << '\n';
  auto get = [&](int x) -> char& {
    x--;
    return a[x % n][x / n];
  };

  for (int _ = 1; _ <= q; _++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int t = x + y * n;
    if (a[x][y] == '*') {
      a[x][y] = '.';
      if (t <= cnt - 1) in--;
      auto c = get(cnt);
      cnt--;
      if (c == '*') in--;
    } else {
      a[x][y] = '*';
      if (t <= cnt - 1) in++;
      cnt++;
      auto c = get(cnt);
      if (c == '*') in++;
    }

    cout << cnt - in << '\n';
  }

  return 0;
}