// date: 2024-05-16 23:44:09
// tag: 构造，数学

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = i * j;
      a[i][j] += b[i] - i * i;
      a[i][j] = (a[i][j] % n + n) % n;
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}