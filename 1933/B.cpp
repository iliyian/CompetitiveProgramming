#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] % 3 == 1) f = true;
  }
  if (sum % 3 == 0) {
    cout << 0 << '\n';
  } else if (sum % 3 == 2) {
    cout << 1 << '\n';
  } else {
    if (f) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
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