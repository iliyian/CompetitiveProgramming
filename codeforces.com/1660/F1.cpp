// date: 2024-04-28 16:42:41
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  str = '#' + str;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (str[i] == '+');
    b[i] = b[i - 1] + (str[i] == '-');
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    int len = 0, cnt = 0;
    for (int r = l + 1; r <= n; r++) {
      if (str[r] == '-') {
        len++;
      } else {
        cnt += len / 2;
        len = 0;
      }

      int rcnt = cnt + len / 2;
      int acnt = a[r] - a[l - 1], bcnt = b[r] - b[l - 1];
      if (bcnt >= acnt && (bcnt - acnt) % 3 == 0
        && (bcnt - acnt) / 3 <= rcnt
        ) {
          ans++;
        }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F1.in", "r", stdin);
  freopen("F1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}