// date: 2024-04-12 17:58:54
// tag: 尺取，双指针

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  vector<vector<int>> s(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      a[i][j] = ch - '0';
      s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }
  auto get = [&](int u, int b, int l, int r) {
    return s[b][r] - s[b][l - 1] - s[u - 1][r] + s[u - 1][l - 1];
  };
  auto calc = [&](int u, int b, int l, int r) {
    return b - u - 1 - get(u + 1, b - 1, r, r)
      + b - u - 1 - get(u + 1, b - 1, l, l)
      + r - l - 1 - get(u, u, l + 1, r - 1)
      + r - l - 1 - get(b, b, l + 1, r - 1)
      + get(u + 1, b - 1, l + 1, r - 1);
  };
  int ans = INT_MAX;
  for (int u = 1; u <= n - 4; u++) {
    for (int b = u + 4; b <= n; b++) {
      for (int r = 4, l = 1; r <= m; r++) {
        int sum1 = calc(u, b, l, r), sum2 = calc(u, b, r - 3, r);
        if (sum2 < sum1) {
          l = r - 3;
        }
        ans = min({ans, sum1, sum2});
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}