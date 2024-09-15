// date: 2024-09-11 11:23:10
// tag: 无向图的团，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::iota(pa.begin() + 1, pa.end(), 1);
  std::vector<int> cnt(n + 1);
  std::vector<std::pair<int, int>> edges(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[x, y] = edges[i];
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    merge(x, y);
  }
  for (int i = 1; i <= m; i++) {
    auto &[x, y] = edges[i];
    cnt[find(find, x)]++;
    cnt[find(find, y)]++;
  }
  int ans = 0, siz0 = LLONG_MAX, siz1 = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i) {
      cnt[i] /= 2;
      int mx = siz[i] * (siz[i] - 1) / 2;
      if (siz[i] < siz0) {
        siz1 = siz0;
        siz0 = siz[i];
      } else if (siz[i] < siz1) {
        siz1 = siz[i];
      }
      ans += mx - cnt[i];
    }
  }
  if (ans == 0) {
    ans = siz1 * siz0;
  }
  std::cout << ans << '\n';
  return 0;
}