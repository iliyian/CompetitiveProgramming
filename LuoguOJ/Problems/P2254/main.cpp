#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {0, -1, 1, 0, 0}, dy[] = {0, 0, 0, -1, 1};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, sx, sy, k;
  cin >> n >> m >> sx >> sy >> k;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector dp(k + 2, vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MIN)));
  // for (int i = 0; i <= k; i++) {
  //   dp[i][sx][sy] = 0;
  // }
  dp[0][sx][sy] = 0;
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto dis = [](int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  };

  int ans = 0;
  auto work = [&](int x, int y, int len, int d, int k) {
    deque<int> q;
    vector<int> xs(300), ys(300);
    for (int i = 1; in(x, y); i++, x += dx[d], y += dy[d]) {
      if (a[x][y] == 'x') {
        q.clear();
        continue;
      }
      xs[i] = x, ys[i] = y;
      while (!q.empty() && dis(x, y, xs[q.front()], ys[q.front()])
         > len) q.pop_front();
      if (!q.empty()) {
        dp[k][x][y] = max(dp[k][x][y], dp[k - 1][xs[q.front()]][ys[q.front()]] +
          dis(x, y, xs[q.front()], ys[q.front()]));
        ans = max(ans, dp[k][x][y]);
      }
      while (!q.empty() && dp[k][x][y] - x - y > 
        dp[k][xs[q.back()]][ys[q.back()]] - xs[q.back()] - ys[q.back()])
          q.pop_back();
      q.push_back(i);
    }
  };

  for (int _ = 1; _ <= k; _++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[_][i][j] = dp[_ - 1][i][j];
      }
    }
    int s, t, d;
    cin >> s >> t >> d;
    int len = t - s + 1;
    if (d == 1) {
      for (int i = 1; i <= m; i++) {
        work(n, i, len, d, _);
      }
    } else if (d == 2) {
      for (int i = 1; i <= m; i++) {
        work(1, i, len, d, _);
      }
    } else if (d == 3) {
      for (int i = 1; i <= n; i++) {
        work(i, m, len, d, _);
      }
    } else {
      for (int i = 1; i <= n; i++) {
        work(i, 1, len, d, _);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}