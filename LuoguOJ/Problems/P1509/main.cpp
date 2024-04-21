// 双重费用变式

#include <bits/stdc++.h>
using namespace std;

int rmb[100], rp[100], t[100];
int dp[101][101], dp2[101][1001];

int main() {
  freopen("data.in", "r", stdin);
  int n, m, r;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> rmb[i] >> rp[i] >> t[i];
  cin >> m >> r;
  dp[0][0] = 1;
  for (int i = 0; i < 101; i++) memset(dp[i], 0, sizeof(dp[i]));
  for (int i = 0; i < n; i++)
    for (int j = m; j >= rmb[i]; j--)
      for (int k = r; k >= rp[i]; k--) {
        int &a = dp[j][k], &b = dp[j - rmb[i]][k - rp[i]];
        int &c = dp2[j][k], &d = dp2[j - rmb[i]][k - rp[i]];
        if (a < b + 1) {
          a = b + 1;
          c = d + t[i];
        } else if (a == b + 1 && c > d + t[i]) c = d + t[i];
      }
  cout << dp2[m][r];
  return 0;
}