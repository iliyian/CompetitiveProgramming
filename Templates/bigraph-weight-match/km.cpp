// date: 2024-03-10 15:25:28
// tag: km，二分图最大权完美匹配
// wa#01: pi[i]和i写反

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      a[j][i] *= x;
    }
  }

  vector<int> lx(n + 1), ly(n + 1), pi(n + 1);
  vector<bool> visx(n + 1), visy(n + 1);
  int minz = inf;

  auto dfs = [&](auto self, int u) -> bool {
    visx[u] = true;
    for (int i = 1; i <= n; i++) {
      if (!visy[i]) {
        int t = lx[u] + ly[i] - a[u][i];
        if (t == 0) {
          visy[i] = true;
          if (pi[i] == 0 || self(self, pi[i])) {
            pi[i] = u;
            return true;
          }
        } else {
          minz = min(minz, t);
        }
      }
    }
    return false;
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      lx[i] = max(lx[i], a[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    while (true) {
      minz = inf;
      fill(visx.begin(), visx.end(), false);
      fill(visy.begin(), visy.end(), false);
      if (dfs(dfs, i)) break;
      for (int j = 1; j <= n; j++) {
        if (visx[j]) {
          lx[j] -= minz;
        }
      }
      for (int j = 1; j <= n; j++) {
        if (visy[j]) {
          ly[j] += minz;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[pi[i]][i];
  }
  cout << ans << '\n';

  return 0;
}