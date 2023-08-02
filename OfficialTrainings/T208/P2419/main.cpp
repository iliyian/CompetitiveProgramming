// 看起来量小必须用floyd啊
// 这类似求传递闭包

#include <bits/stdc++.h>
using namespace std;

bitset<101> e[101];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e[u][v] = true;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        e[i][j] = e[i][j] | (e[i][k] & e[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool f = true;
    for (int j = 1; j <= n; j++)
      if (i != j)
        f &= e[i][j] | e[j][i];
    ans += f;
  }
  cout << ans;
  return 0;
}