// date: 2024/02/01 13:40:15
// tag: 标准区间填表法动态规划，现在推于过去
// 顺便原来 未来推于现在 的叫刷表法

#include <bits/stdc++.h>
#define N 55
using namespace std;

int f[N][N][2];

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> d(n + 1), s(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> d[i] >> w[i], s[i] = s[i - 1] + w[i];
  for (int i = 1; i <= n; i++)
    f[i][i][0] = f[i][i][1] = abs(d[c] - d[i]) * s[n];
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      // 无论从上一个区间的左或者右过来，燃着的灯相同
      f[i][j][0] = min(f[i + 1][j][0] + (d[i + 1] - d[i]) * (s[i] + s[n] - s[j]),
      f[i + 1][j][1] + (d[j] - d[i]) * (s[i] + s[n] - s[j]));
      f[i][j][1] = min(f[i][j - 1][1] + (d[j] - d[j - 1]) * (s[i - 1] + s[n] - s[j - 1]),
      f[i][j - 1][0] + (d[j] - d[i]) * (s[i - 1] + s[n] - s[j - 1]));
    }
  }
  cout << min(f[1][n][0], f[1][n][1]) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}