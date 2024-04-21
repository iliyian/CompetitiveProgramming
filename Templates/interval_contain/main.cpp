// date: 2024/02/17 13:28:58
// tag: pb_ds比离散化然后树状数组简单的多了，
// 平衡树模板，但是平衡树都不用写了...
// 注意其不支持重复值，如果要，可以用pair<T, int>，后者为时间

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    vec.push_back({r, l});
  }
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
  sort(vec.begin(), vec.end());
  int ans = 0;
  for (auto [r, l] : vec) {
    ans += s.size() - s.order_of_key(l);
    s.insert(l);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}