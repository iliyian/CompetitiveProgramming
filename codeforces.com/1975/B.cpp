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
  sort(a.begin() + 1, a.end());
  vector<int> b = a;
  b.erase(unique(b.begin() + 1, b.end()), b.end());

  int x = b[1], y = -1;
  for (int j = 2; j <= n; j++) {
    if (b[j] % x) {
      y = b[j];
      break;
    }
  }
  if (y == -1) {
    cout << "Yes\n";
    return;
  }
  // cout << x << ' ' << y << '\n';

  for (int i = 1; i <= n; i++) {
    if (a[i] % x && a[i] % y) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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