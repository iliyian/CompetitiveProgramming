// date: 2024-07-15 15:13:40
// tag: stl的应用，平衡树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

struct Node {
  int l, r;
  bool operator < (const Node &b) const {
    return r < b.l;
  }
};

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;

  std::multiset<Node> s;

  for (int i = 1; i <= n; i++) {
    char op;
    int l, r;
    std::cin >> op;
    if (op == 'A') {
      std::cin >> l >> r;
      std::cout << s.count({l, r}) << '\n';
      s.erase({l, r});
      s.insert({l, r});
    } else {
      std::cout << s.size() << '\n';
    }
  }

  return 0;
}