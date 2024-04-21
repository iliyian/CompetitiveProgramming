#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  vector<string> a(9);
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
      if (isalpha(a[i][j])) {
        cout << a[i][j];
      }
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}