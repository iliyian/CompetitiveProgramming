// 务必搞清楚 i 和 1 << i - 1 的巨大区别

#include <bits/stdc++.h>
using namespace std;

double x[16], y[16];
double f[1 << 16][16];

double dist(int s, int t) {
  return sqrt((x[s] - x[t]) * (x[s] - x[t]) + (y[s] - y[t]) * (y[s] - y[t]));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  x[0] = y[0] = 0;
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i];

  int sum = (1 << n) - 1;
  memset(f, 127, sizeof(f));

  for (int i = 1; i <= n; i++)
    f[1 << i - 1][i] = dist(0, i);

  for (int S = 1; S <= sum; S++) {
    for (int i = 1; i <= n; i++) {
      if (S & (1 << i - 1)) {
        for (int j = 1; j <= n; j++) {
          if (i != j && (S & (1 << j - 1))) {
            f[S][i] = min(f[S][i], f[S - (1 << i - 1)][j] + dist(i, j));
          }
        }
      }
    }
  }
  double ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    ans = min(ans, f[sum][i]);
  cout << fixed << setprecision(2) << ans;
  return 0;
}
