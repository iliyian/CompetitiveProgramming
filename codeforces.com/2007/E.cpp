// date: 2024-09-03 21:14:38
// tag: dfs与树上路径和性质，树上路径相关的计数，贪心

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

void solve() {
  int n, w;
  std::cin >> n >> w;
  std::vector<int> a(n + 1), dep(n + 1), pa(n + 1), c1(n + 1), c2(n + 1), cnt(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    pa[i] = x;
    dep[i] = dep[x] + 1; // dfs order
  }
  for (int i = 1; i <= n; i++) {
    int x = i, y = i % n + 1;
    while (x != y) {
      if (dep[x] < dep[y]) std::swap(x, y);
      (c1[x] ? c2[x] : c1[x]) = i, cnt[i]++;
      x = pa[x];
    }
  }
  int sum = 0, cur = n;
  for (int i = 2; i <= n; i++) {
    int x, t;
    std::cin >> x >> t;
    sum += t;
    if (!--cnt[c1[x]]) cur--;
    if (!--cnt[c2[x]]) cur--;
    std::cout << sum * 2 + cur * (w - sum) << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}