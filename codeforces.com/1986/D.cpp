#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  if (n == 2) {
    cout << stoi(str) << '\n';
    return;
  }
  int ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 0; i < n - 1; i++) {
    int cur = 0;
    bool f = true;
    for (int j = 0; j < n; j++) {
      int t = 0;
      if (j == i) {
        t = (str[j] - '0') * 10 + str[j + 1] - '0';
        j++;
      } else {
        t = str[j] - '0';
      }

      if (t == 0) {
        cout << 0 << '\n';
        return;
      } else if (t != 1) {
        cur += t;
      } else {
        f = true;
      }
    }
    ans = min(ans, cur);
    if (f) {
      ans = max(ans, 1ll);
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}