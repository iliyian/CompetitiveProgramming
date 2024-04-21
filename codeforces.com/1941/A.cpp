#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    for (int j = 1; j <= n; j++) {
      if (a[j] + b[i] <= k)
        ans++;
      else
        break;
    }
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