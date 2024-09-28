#include <bits/stdc++.h>
using namespace std;
int n, m, s[2000005], T;
vector<bool> dp[2000005], a, b[2000005];
char ch;
void dfs(int cur, int val) {
  if (cur == 0)
    return;
  if (val >= s[cur] && dp[cur - 1][((val - s[cur]) << 1) | a[cur - 1]])
    cout << 0, dfs(cur - 1, ((val - s[cur]) << 1) | a[cur - 1]);
  else
    cout << 1, dfs(cur - 1, ((val - n + s[cur]) << 1) | a[cur - 1]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin >> T;
  while (T--) {
    cin >> n >> m, a.resize(m + 1);
    for (int i = 0; i <= m; i++)
      dp[i].resize(4 * n + 1), s[i] = 0;
    for (int i = m; i >= 1; i--)
      cin >> ch, a[i] = ch ^ 48;
    for (int i = 1; i <= n; i++) {
      b[i].resize(m + 1);
      for (int j = m; j >= 1; j--)
        cin >> ch, b[i][j] = ch ^ 48, s[j] += b[i][j];
    }
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j <= 4 * n; j++)
        if (dp[i][j] && (j & 1) == a[i])
          dp[i + 1][(j >> 1) + s[i + 1]] = 1,
                                     dp[i + 1][(j >> 1) + (n - s[i + 1])] = 1;
    if (dp[m][a[m]])
      dfs(m, a[m]), cout << '\n';
    else
      cout << "-1\n";
    for (int i = 1; i <= n; i++)
      b[i].clear();
    for (int i = 1; i <= m; i++)
      dp[i].clear();
    a.clear();
  }
  return 0;
}