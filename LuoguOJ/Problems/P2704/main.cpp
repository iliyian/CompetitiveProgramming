// date: 2024-04-09 10:36:41
// tag: 状态压缩dp
// 没特判n == 1, 更新ans不及时，没滚动数组

#include <bits/stdc++.h>
#define int long long
using namespace std;

bitset<1050> ok[105];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  
  for (int i = 0; i < n; i++) {
    int bad = 0;
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'H') {
        bad |= 1 << j;
      }
    }
    for (int S = (1 << m) - 1; S >= 0; S--) {
      ok[i][S] = !(S & bad) && !(S & (S << 1)) && !(S & (S << 2));
    }
  }
  vector<vector<vector<int>>>
    f(2, vector<vector<int>>(1 << m, vector<int>(1 << m)));

  int ans = 0, p = 0;
  for (int S = (1 << m) - 1; S >= 0; S--) {
    f[p][S][0] = ok[0][S] * __builtin_popcount(S);
    ans = max(ans, f[p][S][0]);
  }
  if (m <= 1) {
    cout << ans << '\n';
    return 0;
  }
  for (int prv = (1 << m) - 1; prv >= 0; prv--) {
    if (!ok[0][prv]) continue;
    for (int S = (1 << m) - 1; S >= 0; S--) {
      if (!(S & prv) && ok[1][S]) {
        f[p ^ 1][S][prv] = max(f[p ^ 1][S][prv], f[p][prv][0] + __builtin_popcount(S));
        ans = max(ans, f[p ^ 1][S][prv]);
      }
    }
  }
  
  for (int i = 2; i < n; i++) {
    for (int x = (1 << m) - 1; x >= 0; x--) {
      if (!ok[i][x]) continue;
      for (int y = (1 << m) - 1; y >= 0; y--) {
        if (!ok[i - 1][y] || y & x) continue;
        for (int z = (1 << m) - 1; z >= 0; z--) {
          if (!ok[i - 2][z] || z & y || z & x) continue;
          f[p][x][y] = max(f[p][x][y], f[p ^ 1][y][z] + __builtin_popcount(x));
          ans = max(ans, f[p][x][y]);
        }
      }
    }
    p ^= 1;
  }
  cout << ans << '\n';

  return 0;
}