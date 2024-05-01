// date: 2024-04-30 22:30:44
// tag: 位运算，前缀和

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> f(n + 1);
  vector<vector<array<int, 2>>> s(n + 1, vector<array<int, 2>>(31));
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] ^ a[i];
    for (int j = 0; j <= 30; j++) { //是n这一层的前缀和
      s[i][j][1] = s[i - 1][j][1] + (f[i] >> j & 1);
      s[i][j][0] = s[i - 1][j][0] + (f[i] >> j & 1 ^ 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 30; j >= 0; j--) {
      if (a[i] >> j & 1) {
        ans += (s[i - 1][j][0] + 1) * (s[n][j][0] - s[i - 1][j][0])
          + s[i - 1][j][1] * (s[n][j][1] - s[i - 1][j][1]);
        break;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}