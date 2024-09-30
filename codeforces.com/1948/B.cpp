#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  int pre = 0;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if (x < pre) {
      cout << "NO\n";
      return;
    }
    if (x / 10 >= pre && (x / 10 <= x % 10)) {
      pre = x % 10;
    } else {
      pre = x;
    }
  }
  cout << "YES\n";
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