#include <bits/stdc++.h>
#define N 2002
using namespace std;

int f[N][N], ans[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int t, k;
  cin >> t >> k;

  for (int i = 0; i < N; i++) {
    f[i][0] = f[i][i] = 1;
    for (int j = 1; j < i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % k;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
      ans[i][j] += !f[i][j];
    }
    ans[i][i + 1] = ans[i][i];
  }

  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << ans[n][min(n, m)] << '\n';
  }
  return 0;
}