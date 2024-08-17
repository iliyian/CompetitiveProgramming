// date: 2024-08-14 11:59:01
// tag: 带距离权并查集带路径压缩

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n = 30000;
  std::vector<int> pa(n + 1), len(n + 1, 1), dis(n + 1);
  std::iota(pa.begin() + 1, pa.end(), 1);

  auto find = [&](auto self, int x) -> int {
    if (x == pa[x]) return x;
    int p = self(self, pa[x]);
    dis[x] += dis[pa[x]];
    pa[x] = p;
    return p;
  };

  auto merge = [&](int x, int y) -> void {
    x = find(find, x), y = find(find, y);
    // if (x == y) return;
    pa[x] = y;
    dis[x] += len[y];
    len[y] += len[x];
  };

  int q;
  std::cin >> q;
  while (q--) {
    char op;
    std::cin >> op;
    if (op == 'M') {
      int x, y;
      std::cin >> x >> y;
      merge(x, y);
    } else {
      int x;
      std::cin >> x;
      find(find, x);
      std::cout << dis[x] << '\n';
    }
  }

  return 0;
}