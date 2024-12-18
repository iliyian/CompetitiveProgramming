// date: 2024-08-24 21:14:58
// tag: pb_ds平衡树

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, mn;
  std::cin >> n >> mn;

  __gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type, std::greater<std::pair<int, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> s;

  int cur = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    char op;
    int x;
    std::cin >> op >> x;
    if (op == 'I') {
      if (x < mn) {
        continue;
      }
      s.insert({x - cur, i});
    } else if (op == 'A') {
      cur += x;
      while (!s.empty() && s.rbegin()->first + cur < mn) {
        s.erase(s.rbegin());
        cnt++;
      }
    } else if (op == 'S') {
      cur -= x;
      while (!s.empty() && s.rbegin()->first + cur < mn) {
        s.erase(s.rbegin());
        cnt++;
      }
    } else {
      if (x > s.size()) {
        std::cout << -1 << '\n';
        continue;
      }
      int v = s.find_by_order(x - 1)->first;
      std::cout << v + cur << '\n';
    }
  }
  std::cout << cnt << '\n';

  return 0;
}