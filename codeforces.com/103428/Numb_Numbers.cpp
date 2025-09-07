#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert({a[i], i});
  }
  while (q--) {
    int x, v;
    std::cin >> x >> v;
    s.erase({a[x], x});
    a[x] += v;
    s.insert({a[x], x});
    int p = (n - 1) / 2;
    auto l = s.find_by_order(p), r = s.find_by_order(p + 1);
    // std::cout << l->first << ' ' << r->first << '\n';
    if (l->first != r->first) {
      std::cout << (n + 1) / 2 << '\n';
    } else {
      int q = s.order_of_key({l->first, 0});
      std::cout << q << '\n';
    }
  }
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