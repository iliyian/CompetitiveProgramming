// date: 2024-03-04 17:27:49
// tag: 行列式求值
// wa#01: sig 变成 ^=1 了

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, mod;
  cin >> n >> mod;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      a[i][j] %= mod;
    }
  }

  int sig = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      while (a[i][i]) {
        int div = a[j][i] / a[i][i];
        for (int k = i; k <= n; k++) {
          a[j][k] = (a[j][k] - div * a[i][k] % mod + mod) % mod;
        }
        swap(a[i], a[j]);
        sig = -sig;
      }
      swap(a[i], a[j]);
      sig = -sig;
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * a[i][i] % mod;
  }
  ans *= sig;
  ans = (ans % mod + mod) % mod;
  cout << ans << '\n';

  return 0;
}