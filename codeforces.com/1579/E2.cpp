// date: 2024-04-13 12:00:21
// tag: 贪心，逆序对，pb_ds

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int ans = 0;
  tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int c1 = s.order_of_key({a[i], 0});
    int c2 = s.size() - s.order_of_key({a[i], n});
    ans += min(c1, c2);
    s.insert({a[i], i});
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E2.in", "r", stdin);
  freopen("E2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}