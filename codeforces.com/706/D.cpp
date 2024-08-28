// date: 2024-08-18 16:35:42
// tag: 01trie

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int q;
  std::cin >> q;
  std::vector<std::array<int, 2>> tr(q << 5);
  std::vector<int> cnt(q << 5);
  int tot = 0;

  auto insert = [&](int x, int c) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!tr[u][idx]) tr[u][idx] = ++tot;
      u = tr[u][idx];
      cnt[u] += c;
    }
  };

  insert(0, 1);
  auto query = [&](int x) {
    int ans = 0, u = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (cnt[tr[u][idx ^ 1]]) {
        u = tr[u][idx ^ 1];
        ans += 1 << i;
      } else {
        u = tr[u][idx];
      }
    }
    return ans;
  };

  while (q--) {
    char op;
    int x;
    std::cin >> op >> x;
    if (op == '+') insert(x, 1);
    else if (op == '-') insert(x, -1);
    else std::cout << query(x) << '\n';
  }

  return 0;
}