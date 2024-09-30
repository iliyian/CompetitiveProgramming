#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> a(2);
  cin >> a[0] >> a[1];
  string ans;
  int p = -1, cnt = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[0][i + 1] > a[1][i]) {
      p = i;
      break;
    }
    if (a[0][i + 1] == a[1][i]) {
      for (int j = i; j < n - 1; j++) {
        if (a[0][j + 1] < a[1][j]) {
          i = j;
          break;
        } else if (a[0][j + 1] > a[1][j]) {
          p = j;
          break;
        }
      }
    }
    if (p >= 0) break;
  }
  if (p == -1) p = 0;

  for (int i = p + 1; i < n - 1; i++) {
    if (a[0][i + 1] == a[1][i]) {
      cnt++;
    } else {
      break;
    }
  }
  cout << a[0].substr(0, p + 1) << a[1].substr(p, n - p) << '\n';
  cout << cnt << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}