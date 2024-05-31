#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.check.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    set<int> s;
    int x = 0;
    for (int j = i; j <= n; j++) {
      s.insert(a[j]);
      x |= a[j];
      if (j > i && x > *s.rbegin()) {
        ans++;
        // cout << i << ' ' << j << '\n';
      }
    }
  }
  cout << ans << '\n';

  return 0;
}