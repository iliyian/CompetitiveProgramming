// date: 2024-05-08 11:37:58
// tag: 数学，构造

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int ans = 1, l = min(pos[0], pos[1]), r = max(pos[0], pos[1]);
  for (int i = 2; i <= n; i++) {
    if (l <= pos[i] && pos[i] <= r) {
      ans *= r - l - 1 - (i - 2);
      ans %= mod;
    }
    l = min(l, pos[i]), r = max(r, pos[i]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}