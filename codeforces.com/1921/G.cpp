// date: 2024/02/15 15:12:45
// tag: wa#01: 斜线前缀和两边都有可能出界
// 本题一点也不dp
// 转图形转换为转背景，同时注意swap(n, m)

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }
  for (int _ = 0; _ < 4; _++) {
    // 注意旋转的时候swap(n, m);
    vector<vector<int>> a(n + 1, vector<int>(m + 1)),
      b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = a[i - 1][j] + (s[i][j] == '#');
        // 没必要算二维矩形前缀和
        b[i][j] = b[i - 1][j - 1] + (s[i][j] == '#');
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum = sum + a[min(n, i + k)][j] - a[i - 1][j];
        // sum -= b[i + k - 1, j - 1] - b[i - 1][j - k - 2]; //上一个的上一个
        int si = i + k, sj = j - 1;
        if (si > n) {
          sj -= si - n;
          si = n;
        }
        sum -= b[si][max(0ll, sj)] - b[max(0ll, i - 1)][max(0ll, j - k - 2)];
        ans = max(ans, sum);
      }
      sum = 0;
    }
    
    swap(n, m);
    vector<string> t(n + 1, string(m + 1, '.'));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        t[i][j] = (s[m - j + 1][i]);
      }
    }
    s = t;
  }
  cout << ans << '\n';
}

//

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}