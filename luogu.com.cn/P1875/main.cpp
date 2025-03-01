// date: 2024/01/27 20:16:48
// tag: 已知更新未知的动态规划思想，以及乘法原理
// todo: 疑似可以用根堆

#include <bits/stdc++.h>
#define N 1005
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

int f[N][N], a[N], ans[N], cost[N];
bitset<N> v;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans[i] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      f[i][j] = f[j][i] = -1;
  int x, y, z;
  while (cin >> x >> y >> z) {
    f[x][y] = f[y][x] = z;
  }

  for (int i = 0; i < n; i++) {
    int minn = inf, t = -1;
    for (int j = 0; j < n; j++) {
      if (minn > a[j] && !v[j]) {
        minn = a[j], t = j;
      }
    }
    v[t] = true;

    for (int j = 0; j < n; j++) {
      if (f[t][j] >= 0 && v[j]) {
        if (a[f[t][j]] == a[t] + a[j]) {
          ans[f[t][j]] += ans[t] * ans[j];
        } else if (a[f[t][j]] > a[t] + a[j]) {
          a[f[t][j]] = a[t] + a[j];
          ans[f[t][j]] = ans[t] * ans[j];
        }
      }
    }
  }
  cout << a[0] << ' ' << ans[0];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}