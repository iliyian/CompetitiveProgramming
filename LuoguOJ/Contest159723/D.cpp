#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, q, V;
  cin >> n >> q >> V;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = y;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] >= V;
  }
  cout << ans << '\n';

  return 0;
}