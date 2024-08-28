// date: 2024-08-24 19:26:11
// tag: 可删除并查集，pb_ds可并堆

// 据说__gnu_pbds::pairing_heap_tag更快，
//                      push pop modify erase join
// pairing_heap_tag     O(1),均摊O(logn),均摊O(logn),均摊O(logn),O(1)
// rc_binomial_heap_tag O(1),O(logn),O(logn),O(logn),O(logn)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  typedef __gnu_pbds::priority_queue<std::pair<int, int>, std::greater<std::pair<int, int>>, __gnu_pbds::rc_binomial_heap_tag> pq;

  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(n + 1), siz(n + 1, 1), del(n + 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  std::vector<pq> q(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    q[i].push({x, i});
  }
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> y;
      if (del[x] || del[y]) continue;
      x = find(find, x), y = find(find, y);
      if (x == y) continue;
      q[x].join(q[y]);
      pa[y] = x;
    } else {
      std::cin >> x;
      if (del[x]) {
        std::cout << -1 << '\n';
        continue;
      }
      x = find(find, x);
      std::cout << q[x].top().first << '\n';
      int id = q[x].top().second;
      del[id] = true;
      q[x].pop();
    }
  }

  return 0;
}