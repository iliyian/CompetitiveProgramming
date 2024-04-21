#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> x(k + 1), a(n + 1), b(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(x.begin() + 1, x.end());



  cout << ans << '\n';
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