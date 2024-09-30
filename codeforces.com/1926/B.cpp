#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  int cnt = 0, prv = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt += a[i][j] == '1';
    }
    if (prv > 0 && cnt > 0) {
      cout << (prv == cnt ? "SQUARE" : "TRIANGLE") << '\n';
      return;
    }
    prv = cnt;
    cnt = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}