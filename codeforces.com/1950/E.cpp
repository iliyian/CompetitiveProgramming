#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int ans = n;
  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        string pat = str.substr(0, i);
        int cnt = 0;
        bool f = true;
        for (int j = i; j < n; j++) {
          if (str[j] != str[j % i]) {
            cnt++;
            if (cnt > 1) {
              f = false;
              break;
            }
          }
        }
        if (f) {
          ans = min(ans, i);
          break;
        }
      }
    }
    reverse(str.begin(), str.end());
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}