// date: 2025-05-06 19:32:57
// tag: 只能说这题目描述真弱智

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace __gnu_pbds;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  std::map<int, int> dic;
  tree<std::pair<int, int>, null_type, std::greater<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    s.insert({a[i].second, a[i].first});
  }
  int ans = 0, cnt = 0;
  int tot = 0;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    auto p = s.find_by_order(i - 1);
    // std::cerr << i << ' ' << p->first << ' ' << s.size() << '\n';
    if (ans < p->first * i) {
      ans = p->first * i;
      cnt = i;
    }
    s.erase({a[a[i].first].second, a[a[i].first].first});
  }
  std::cout << ans << ' ' << cnt << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}