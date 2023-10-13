#include <bits/stdc++.h>
using namespace std;

int n, r;

double p[21], f[21][21];

double solve(int idx) {
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (i == idx) {
      for (int j = 0; j <= min(r, i); j++)
        f[i][j] = f[i - 1][j]; // move
    } else {
      for (int j = 0; j <= min(r, i); j++) {
        f[i][j] = f[i - 1][j] * (1 - p[i]);
        if (j) f[i][j] += f[i - 1][j - 1] * p[i];
      }
    }
  }
  return idx ? f[n][r - 1] * p[idx] : f[n][r];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  for (int T = 1;; T++) {
    cin >> n >> r;
    if (!n && !r) break;
    for (int i = 1; i <= n; i++)
      cin >> p[i];
    cout << "Case " << T << ":\n";
    double PB = solve(0);
    for (int i = 1; i <= n; i++)
      cout << fixed << setprecision(6) << solve(i) / PB << '\n';
  }
  return 0;
}