#include <bits/stdc++.h>
using namespace std;

array<array<int, 1001>, 1001> a, sum, ans;

int main() {
  freopen("data.in", "r", stdin);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  int x, y, ANS = -1 << 30;
  for (int i = c; i <= n; i++) {
    for (int j = c; j <= m; j++) {
      ans[i][j] = sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c];
      if (ans[i][j] > ANS) {
        ANS = ans[i][j];
        x = i - c + 1, y = j - c + 1;
      }
    }
  }
  cout << x << ' ' << y;
  return 0;
}