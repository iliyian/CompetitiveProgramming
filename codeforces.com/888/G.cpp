// date: 2024-07-11 13:07:01
// tag: 01trie，boruvka，mst

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

constexpr int N = 5e6;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());

  std::vector<std::array<int, 2>> trie(N);
  std::vector<int> L(N), R(N);

  int tot = 0;

  auto insert = [&](int x, int id) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!L[u]) L[u] = id;
      R[u] = id;

      if (!trie[u][idx]) trie[u][idx] = ++tot;
      u = trie[u][idx];
    }
  };

  auto query = [&](auto self, int u, int x, int dep) -> int {
    if (dep == -1) return 0;
    int idx = x >> dep & 1;
    if (trie[u][idx]) return self(self, trie[u][idx], x, dep - 1);
    return self(self, trie[u][idx ^ 1], x, dep - 1) + (1 << dep);
  };

  auto dfs = [&](auto self, int u, int dep) -> int {
    if (dep == -1) return 0;
    if (trie[u][0] && trie[u][1]) {
      int ans = inf;
      for (int i = L[trie[u][0]]; i <= R[trie[u][0]]; i++) {
        ans = std::min(ans, query(query, trie[u][1], a[i], dep - 1) + (1 << dep));
      }
      return ans + self(self, trie[u][0], dep - 1) + self(self, trie[u][1], dep - 1);
    }
    if (trie[u][0]) return self(self, trie[u][0], dep - 1);
    if (trie[u][1]) return self(self, trie[u][1], dep - 1);
    return 0;
  };

  for (int i = 1; i <= n; i++) {
    insert(a[i], i);
  }

  std::cout << dfs(dfs, 0, 30) << '\n';

  return 0;
}