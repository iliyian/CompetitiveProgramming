// date: 2024-03-11 12:22:57
// tag: 二分图最大权完美匹配
// wa,tle#01: 没有考虑到负权边，而使不存在的边的边权为0而非-inf
// 且卡O(n^4)
// wa#02: 没有考虑到负权边，而使不存在的边的边权为0而非-inf

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(n + 1, -inf));
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u][v] = w;
  }
  vector<bool> visx(n + 1), visy(n + 1);
  vector<int> lx(n + 1), ly(n + 1), px(n + 1), py(n + 1),
    slack(n + 1), pre(n + 1);
  queue<int> q;

  auto check = [&](int v) {
    visy[v] = true;
    if (py[v]) {
      visx[py[v]] = true;
      q.push(py[v]);
      return false;
    }
    while (v) {
      py[v] = pre[v];
      swap(v, px[pre[v]]);
    }
    return true;
  };

  auto bfs = [&](int s) {
    while (!q.empty()) {
      q.pop();
    }
    q.push(s);
    visx[s] = true;
    while (true) {
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; v++) {
          if (!visy[v]) {
            int t = lx[u] + ly[v] - a[u][v];
            if (t <= slack[v]) {
              pre[v] = u;
              if (t) {
                slack[v] = t;
              } else if (check(v)) {
                return;
              }
            }
          }
        }
      }
      int minz = inf;
      for (int i = 1; i <= n; i++) {
        if (!visy[i]) {
          minz = min(minz, slack[i]);
        }
      }
      for (int i = 1; i <= n; i++) {
        if (visx[i]) lx[i] -= minz;
        if (visy[i]) ly[i] += minz;
        else slack[i] -= minz;
      }
      for (int i = 1; i <= n; i++) {
        if (!slack[i] && !visy[i] && check(i)) {
          return;
        }
      }
    }
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      lx[i] = max(lx[i], a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    fill(slack.begin(), slack.end(), inf);
    fill(visx.begin(), visx.end(), false);
    fill(visy.begin(), visy.end(), false);
    bfs(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i][px[i]];
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    cout << py[i] << " \n"[i == n];
  }

  return 0;
}