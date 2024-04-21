#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    multiset<int> vis;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (vis.find(a[i] ^ INT_MAX) != vis.end()) {
        vis.erase(vis.find(a[i] ^ INT_MAX));
      } else {
        vis.insert(a[i]);
        ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}