#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace __gnu_pbds;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert({x, i});
    if (i % 2 == 1) {
      std::cout << s.find_by_order((i - 1) / 2)->first << ' ';
    } else {
      int x = s.find_by_order((i - 1) / 2)->first, y = s.find_by_order((i - 1) / 2 + 1)->first;
      std::cout << (x + y) / 2 << ' ';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}