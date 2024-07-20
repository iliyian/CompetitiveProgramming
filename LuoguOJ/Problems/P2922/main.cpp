// date: 2024-07-15 11:24:35
// tag: 01trie

#include <bits/stdc++.h>
#define int long long
#define N 3e6
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::array<int, 2>> trie(N);
  std::vector<int> cnt(N), val(N);
  int tot = 0;

  auto insert = [&](int c) {
    int u = 0;
    for (int i = 0; i < c; i++) {
      int x;
      std::cin >> x;
      if (!trie[u][x]) trie[u][x] = ++tot;
      u = trie[u][x];
      val[u]++;
    }
    cnt[u]++;
  };

  for (int i = 1; i <= n; i++) {
    int c;
    std::cin >> c;
    insert(c);
  }

  auto calc = [&](int c) -> int {
    int u = 0, ans = 0;
    std::vector<int> x(c + 1);
    for (int i = 0; i < c; i++) {
      std::cin >> x[i];
    }
    for (int i = 0; i < c; i++) {
      if (!trie[u][x[i]]) return ans;
      u = trie[u][x[i]];
      ans += cnt[u];
    }
    ans -= cnt[u];
    ans += val[u];
    return ans;
  };

  for (int i = 1; i <= m; i++) {
    int c;
    std::cin >> c;
    std::cout << calc(c) << '\n';
  }

  return 0;
}