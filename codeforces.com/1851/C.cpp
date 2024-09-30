#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n + 1);
  vector<pair<int, int>> cnt(n + 1);
  int lcnt = 0, rcnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    rcnt += c[i] == c[n];
  }
  if (c[1] == c[n] && rcnt >= k) {
    cout << "YES\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    lcnt += c[i] == c[1];
    rcnt -= c[i] == c[n];
    if (lcnt >= k && rcnt >= k) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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