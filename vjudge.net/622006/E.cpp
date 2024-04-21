#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> l(n + 1), r(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    
  }
  cout << ans << '\n';

  return 0;
}