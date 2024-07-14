// date: 2024-07-10 12:53:20
// tag: 01trie，位运算

#include <bits/stdc++.h>
// #define int long long
// using namespace std;

constexpr int N = 2000000;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  std::vector<std::vector<int>> trie(N, std::vector<int>(2));
  std::vector<int> cnt(N);

  int tot = 1;

  auto insert = [&](int x, int c) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = (x >> i & 1);
      cnt[u] += c;
      if (!trie[u][idx]) trie[u][idx] = ++tot;
      u = trie[u][idx];
    }
    cnt[u] += c;
  };

  int n;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    int op, p, l;
    std::cin >> op;
    if (op == 1) {
      std::cin >> p;
      insert(p, 1);
    } else if (op == 2) {
      std::cin >> p;
      insert(p, -1);
    } else {
      std::cin >> p >> l;
      int ans = 0, u = 1;
      for (int i = 30; i >= 0; i--) {
        int ip = p >> i & 1, il = l >> i & 1;
        if (il == 1) {
          ans += cnt[trie[u][ip]];
        }
        u = trie[u][ip ^ il];
      }
      std::cout << ans << '\n';
    }
  }

  return 0;
}