// date: 2024-04-27 12:02:32
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    char x;
    cin >> x;
    a[i] = x == '1';
  }
  for (int k = n; k >= 1; k--) {
    int cnt = 0;
    vector<int> d(n + 1);
    bool f = true;
    for (int i = 1; i <= n; i++) {
      if (d[i]) cnt--;
      if ((a[i] + cnt) % 2 == 0) {
        if (i + k > n + 1) {
          f = false;
          break;
        }
        cnt++;
        if (i + k <= n) {
          d[i + k]++;
        }
      }
    }
    if (f) {
      cout << k << '\n';
      return;
    }
  }
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