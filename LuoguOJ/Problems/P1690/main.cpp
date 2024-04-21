// 原来用next_permutation前要排序

#include <bits/stdc++.h>
using namespace std;

int a[101][101], t[101];

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  int p;
  cin >> p;
  for (int i = 0; i < p; i++)
    cin >> t[i];
  sort(t, t + p);
  int ans = 1 << 30;
  do {
    int sum = a[1][t[0]] + a[t[p - 1]][n];
    for (int i = 1; i <= p - 1; i++)
      sum += a[t[i - 1]][t[i]];
    ans = min(ans, sum);
  } while (next_permutation(t, t + p));
  cout << ans;
  return 0;
}