#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(4));
  vector<vector<int>> b(n + 1, vector<int>(4));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> b[i][j];
    }
  }
  vector<vector<int>> res(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int tru = 0, ans = 0;
      bool f = true;
      for (int k = 1; k <= 4; k++) {
        if (a[i][k] == b[j][k] && a[i][k] == 1) ans++, tru++;
        else if (!a[i][k] && b[j][k]) {
          res[i][j] = 0;
          f = false;
          break;
        } else if (a[i][k] && !b[j][k]) {
          tru++;
        }
      }
      if (f) {
        if (ans == 0) res[i][j] = 0;
        else if (tru == ans) res[i][j] = 6;
        else res[i][j] = 3;
      }
    }
  }
  for (int o = 0; o < n; o++) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += res[(i + o - 1) % n + 1][i];
    }
    cout << sum << ' ';
  }

  return 0;
}