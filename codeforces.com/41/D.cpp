// date: 2024-05-16 11:57:49
// tag: dp

#include <bits/stdc++.h>
#define int long long
#define N 100
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  vector<vector<bitset<N * 10>>> f(n + 1, vector<bitset<N * 10>>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      a[i][j] = ch - '0';
    }
  }

  for (int i = 1; i <= m; i++) {
    f[n][i][a[n][i]] = true;
  }

  int mxj = -1, mx = -1;
  vector<vector<vector<int>>> prv(n + 1, vector<vector<int>>(m + 1, vector<int>(n * 10)));
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      for (int p = a[i][j]; p <= (n - i + 1) * 9; p++) {
        bool r = f[i + 1][j - 1][p - a[i][j]];
        bool l = f[i + 1][j + 1][p - a[i][j]];

        if (l) {
          prv[i][j][p] = -1;
        } else if (r) {
          prv[i][j][p] = 1;
        }
        f[i][j][p] = l | r;

        if (i == 1 && f[i][j][p] && p % (k + 1) == 0) {
          if (p > mx) {
            mxj = j, mx = p;
          }
        }
      }
    }
  }

  if (mx == -1) {
    cout << -1 << '\n';
    return 0;
  }

  cout << mx << '\n';
  
  stack<int> ans;
  int i = 1, j = mxj, p = mx;
  while (i < n) {
    ans.push(prv[i][j][p]);
    p -= a[i][j];
    j -= prv[i][j][p + a[i][j]];
    i++;
  }
  cout << j << '\n';
  while (!ans.empty()) {
    cout << (ans.top() == -1 ? 'L' : 'R');
    ans.pop();
  }

  return 0;
}