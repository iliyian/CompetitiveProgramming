// date: 2024-08-24 21:32:03
// tag: 平衡树

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  __gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type, std::less<std::pair<int, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> s;
  int sum = 0, pri = 0;

  while (true) {
    int op;
    std::cin >> op;
    if (op == -1) {
      std::cout << sum << ' ' << pri << '\n';
      break;
    }
    if (op == 1) {
      int x, y;
      std::cin >> x >> y;
      if (s.lower_bound({y, 0})->first == y) {
        continue;
      }
      sum += x;
      pri += y;
      s.insert({y, x});
    } else if (op == 2) {
      pri -= s.rbegin()->first;
      sum -= s.rbegin()->second;
      s.erase(s.rbegin());
    } else {
      pri -= s.begin()->first;
      sum -= s.begin()->second;
      s.erase(s.begin());
    }
  }

  return 0;
}