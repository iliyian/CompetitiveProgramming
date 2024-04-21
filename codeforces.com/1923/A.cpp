#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int l = 0, r = n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      if (!l) l = i;
      r = i;
    }
  }
  int ans = 0;
  for (int i = l; i <= r; i++) {
    ans += !a[i];
  }
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