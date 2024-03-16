// date: 2024/02/17 14:59:57
// tag: pb_ds 普通平衡树，注意有相同值需要如下特殊处理

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

void solve() {
  int n;
  cin >> n;
  tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
  for (int t = 0; t < n; t++) {
    int opt, x;
    cin >> opt >> x;
    if (opt == 1) {
      s.insert({x, t});
    } else if (opt == 2) {
      s.erase(s.lower_bound({x, 0}));
    } else if (opt == 3) {
      cout << s.order_of_key({x, 0}) + 1 << '\n';
    } else if (opt == 4) {
      cout << s.find_by_order(x - 1)->first << '\n';
    } else if (opt == 5) {
      cout << prev(s.lower_bound({x, 0}))->first << '\n';
    } else if (opt == 6) {
      cout << s.upper_bound({x, n})->first << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}