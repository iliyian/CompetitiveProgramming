// date: 2024-05-17 17:03:05
// tag: 组合数

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<array<int, 21>> a(n + 1, array<int, 21>{});
  map<array<int, 21>, int> cnt;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      cin >> a[i][j];
    }
    cnt[a[i]]++;
  }
  
  map<array<int, 21>, int> sum;
  for (int i = 1; i <= n; i++) {
    array<int, 21> x = a[i];
    for (int j = 1; j < i; j++) {
      array<int, 21> c{}, y = a[j];
      for (int o = 1; o <= k; o++) {
        if (a[i][o] == a[j][o]) {
          c[o] = a[i][o];
        } else {
          for (int u = 0; u < 3; u++) {
            if (u != a[i][o] && u != a[j][o]) {
              c[o] = u;
              break;
            }
          }
        }
      }
      int cn = cnt[c];
      if (cn) {
        sum[x] += cn, sum[y] += cn, sum[c] += cn;
      }
    }
  }
  int ans = 0;
  for (auto [k, v] : sum) {
    int t = v / 3;
    if (t >= 2) {
      ans += t * (t - 1) / 2;
    }
  }
  cout << ans << '\n';

  return 0;
}