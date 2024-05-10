// date: 2024-05-09 21:05:03
// tag: 高斯消元

#include <bits/stdc++.h>
#define N 1000
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> b(n + 1, vector<int>(n + 1));
  vector<bitset<N * 2 + 5>> a(n * 2 + 1);
  int cnt = 0;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = 1; j <= n; j++) {
      cin >> b[i][j];
      if (b[i][j] == -1) {
        if (cnt > n * 2) {
          f = false;
          continue;
        } else {
          a[i][++cnt] = 1;
          a[j + n][cnt] = 1;
        }
      } else {
        x ^= b[i][j];
      }
    }
    a[i][n * 2 + 1] = x;
  }
  for (int j = 1; j <= n; j++) {
    int x = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i][j] != -1) {
        x ^= b[i][j];
      }
    }
    a[j + n][n * 2 + 1] = x;
  }
  if (cnt > n * 2) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) {
      a[i][n * 2 + 1].flip();
    }
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) {
      a[i + n][n * 2 + 1].flip();
    }
  }

  // for (int i = 1; i <= n * 2; i++) {
  //   for (int j = 1; j <= n * 2 + 1; j++) {
  //     cerr << a[i][j] << ' ';
  //   }
  //   cerr << '\n';
  // }

  int r = 1, mx = 0, m = n * 2;
  for (int c = 1; c <= cnt; c++) {
    r = c;
    while (r <= m && !a[r][c]) r++;
    if (r > m) {
      cout << -1 << '\n';
      return;
    }
    swap(a[r], a[c]);
    mx = max(r, mx);
    for (int i = 1; i <= m; i++) {
      if (i != c && a[i][c]) {
        a[i] ^= a[c];
      }
    }
  }
  // cout << mx << '\n';
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[i][j] == -1) {
        cout << a[++tot][n * 2 + 1] << ' ';
      } else {
        cout << b[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  solve();

  return 0;
}