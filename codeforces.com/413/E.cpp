// date: 2024-08-22 12:44:06
// tag: 倍增，二维图最短路

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::array<std::string, 2> a;
  std::cin >> a[0] >> a[1];
  a[0] = '#' + a[0];
  a[1] = '#' + a[1];

  std::vector<std::vector<int>> st(21, std::vector<int>(n * 2 + 1));
  for (int i = 1; i <= n * 2; i++) {
    int x = (i - 1) / n, y = (i - 1) % n + 1;
    if (a[x][y] == -1) st[0][i] = -1;
    else if (y + 1 > n || a[x][y + 1] == 'X') {
      if (a[x ^ 1][y] == 'X') st[0][i] = -1;
      else st[0][i] = (x ^ 1) * n + y;
    } else {
      st[0][i] = i + 1;
    }
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = n * 2; j >= 1; j--) {
      if (st[i - 1][j] != -1) {
        st[i][j] = st[i - 1][st[i - 1][j]];
      } else {
        st[i][j] = -1;
      }
    }
  }

  while (m--) {
    int s, t;
    std::cin >> s >> t;
    if ((s - 1) % n > (t - 1) % n) std::swap(s, t);
    int ans = 0;
    int tx = (t - 1) / n, ty = (t - 1) % n + 1;
    int sx = (s - 1) / n, sy = (s - 1) % n + 1;
    if (sy == ty) {
      std::cout << (sx != tx) << '\n';
      continue;
    }
    for (int i = 20; i >= 0; i--) {
      int nxt = st[i][s];
      if (nxt == -1) continue;
      int x = (nxt - 1) / n, y = (nxt - 1) % n + 1;
      if (y < ty) {
        s = nxt, ans += 1 << i;
      }
    }
    if ((st[0][s] - 1) % n + 1 == ty) {
      std::cout << ans + 1 + ((st[0][s] - 1) / n != tx) << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }

  return 0;
}