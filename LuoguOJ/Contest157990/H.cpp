#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, t, m;
  cin >> n >> t >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    a[x] -= 2;
  }
  sort(a.begin() + 1, a.end(), greater());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) {
      ans++;
    } else if (a[i] + t > 0 && t > 0) {
      t -= - a[i] + 1;
      a[i] = 1;
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}