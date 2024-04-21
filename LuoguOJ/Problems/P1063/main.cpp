#include <bits/stdc++.h>
using namespace std;

int a[201], m[201], r[201], f[201][201];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("data.in", "r", stdin);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    a[i + N] = a[i];
    m[i] = r[i - 1] = m[i + N] = r[i + N - 1] = a[i];
  }
  r[N * 2] = a[1];
  memset(f, -0x3f, sizeof(f));
  for (int i = 1; i <= N * 2; i++) {
    f[i][i] = 0;
  }
  for (int len = 2; len <= N * 2; len++) {
    for (int i = 1; i <= N * 2 - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + m[i] * r[j] * r[k]); // r[k] == m[k + 1]
    }
  }
  int ans = -0x3f3f3f3f;
  for (int i = 1; i <= N; i++)
    ans = max(ans, f[i][i + N - 1]);
  cout << ans;
  return 0;
}