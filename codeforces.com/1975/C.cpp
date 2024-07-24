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
  if (n == 2) {
    cout << min(a[1], a[2]) << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    array<int, 3> t = {a[i], a[i + 1], a[i + 2]};
    sort(t.begin(), t.end());
    ans = max(ans, t[1]);
  }
  cout << ans << '\n';
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