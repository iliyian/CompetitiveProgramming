#include <bits/stdc++.h>
using namespace std;

int a[201], minf[201][201], maxf[201][201], sum[201];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  sum[0] = 0;
  memset(minf, 0x3f, sizeof(minf));
  memset(maxf, -0x3f, sizeof(maxf));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    minf[i][i] = maxf[i][i] = 0;
  }
  for (int i = n + 1; i <= n * 2; i++) {
    a[i] = a[i - n];
    sum[i] = sum[i - 1] + a[i];
    minf[i][i] = maxf[i][i] = 0;
  }

  for (int len = 2; len <= n * 2; len++) {
    for (int i = 1; i <= n * 2 - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        minf[i][j] = min(minf[i][j], minf[i][k] + minf[k + 1][j] + sum[j] - sum[i - 1]),
        maxf[i][j] = max(maxf[i][j], maxf[i][k] + maxf[k + 1][j] + sum[j] - sum[i - 1]);
    }
  }
  int maxn = -0x3f3f3f3f, minn = 0x3f3f3f3f;
  for (int i = 1; i <= n + 1; i++) {
    maxn = max(maxn, maxf[i][i + n - 1]);
    minn = min(minn, minf[i][i + n - 1]);
  }
  cout << minn << '\n' << maxn;
  return 0;
}