#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  bool f = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    if (i > 1 && a[i] < a[i - 1]) {
      if (!f) {
        cout << "No\n";
        return;
      }
      f = false;
    }
  }
  if (a[1] < a[n] && !f) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}