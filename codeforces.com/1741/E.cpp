// date: 2024-05-17 20:44:12
// tag: dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n + 1);
  vector<int> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (i - b[i] - 1 >= 0) {
      f[i] |= f[i - b[i] - 1];
    }
    if (f[i - 1] && i + b[i] <= n) {
      f[i + b[i]] = 1;
    }
  }
  cout << (f[n] ? "YES" : "NO") << '\n';
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