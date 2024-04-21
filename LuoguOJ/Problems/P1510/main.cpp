// v和w原来可以灵活转换，V是v
// 顺便ios那一行代码几乎可以比快读快写快

#include <bits/stdc++.h>
using namespace std;

int v[10000], w[10000], dp[10001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int V, n, c, sumv = 0;
  cin >> V >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> w[i];
    sumv += v[i];
  }
  if (sumv < V) {
    cout << "Impossible";
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = c; j >= w[i]; j--)
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  for (int i = 0; i <= c; i++)
    if (dp[i] >= V) {
      cout << c - i;
      return 0;
    }
  cout << "Impossible";
  return 0;
}