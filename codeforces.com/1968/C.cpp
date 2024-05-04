#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> x[i];
  }
  vector<int> a(n + 1);
  a[1] = 501;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + x[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
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