// date: 2024-05-31 15:00:40
// tag: 单调队列优化dp

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
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
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
  dp[sx][sy] = 0;
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  int ans = 0;
  auto work = [&](int x, int y, int len, int d) {
    deque<pair<int, int>> q;
    for (int i = 1; in(x, y); i++, x += dx[d], y += dy[d]) {
      if (a[x][y] == 'x') {
        q.clear();
        continue;
      }
      while (!q.empty() && i - q.front().second > len) q.pop_front();
      while (!q.empty() && dp[x][y] > i + q.back().first - q.back().second)
        q.pop_back(); // 递减队列，又旧又蠢的该死
      q.push_back({dp[x][y], i});
      dp[x][y] = max(dp[x][y], q.front().first + i - q.front().second);
      ans = max(ans, dp[x][y]);
    }
  };

  for (int cur = 1; cur <= k; cur++) {
    int s, t, d;
    cin >> s >> t >> d;
    int len = t - s + 1;
    if (d == 1) {
      for (int u = 1; u <= m; u++) {
        work(n, u, len, d);
      }
    } else if (d == 2) {
      for (int u = 1; u <= m; u++) {
        work(1, u, len, d);
      }
    } else if (d == 3) {
      for (int u = 1; u <= n; u++) {
        work(u, m, len, d);
      }
    } else {
      for (int u = 1; u <= n; u++) {
        work(u, 1, len, d);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}