#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::ranges::iota(pa, 0);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (!merge(x, y)) {
      ans++;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += find(i) == i;
  }
  std::cout << ans + cnt - 1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}