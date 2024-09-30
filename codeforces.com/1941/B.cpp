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
  for (int i = 1; i <= n - 2; i++) {
    if (a[i + 1] < a[i] * 2 || a[i + 2] < a[i]) {
      cout << "NO\n";
      return;
    }
    a[i + 1] -= a[i] * 2;
    a[i + 2] -= a[i];
  }
  if (a[n - 1] || a[n]) {
    cout << "NO\n";
    return;
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