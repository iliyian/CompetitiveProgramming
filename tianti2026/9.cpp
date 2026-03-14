#include <bits/stdc++.h>
#define int long long

using i128 = __int128;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> v(m + 1), a(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    std::cin >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      std::cin >> x;
      a[i].push_back(x);
    }
  }
  std::vector<int> pa2(m + 1), siz2(m + 1, 1);
  for (int i = 1; i <= m; i++) {
    pa2[i] = i;
  }
  auto find = [&](auto self, int x, std::vector<int> &pa) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x], pa);};
  auto merge = [&](int x, int y, std::vector<int> &pa, std::vector<int> &siz) -> bool {
    x = find(find, x, pa), y = find(find, y, pa);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
    return true;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < a[i].size(); j++) {
      merge(a[i][j], a[i][0], pa2, siz2);
    }
  }
  std::vector<int> mn(m + 1, LLONG_MAX / 3);
  for (int i = 1; i <= m; i++) {
    int p = find(find, i, pa2);
    mn[p] = std::min(mn[p], i);
    // std::cerr << i << ' ' << p << '\n';
  }
  std::vector<int> ans;
  for (int i = 1; i <= m; i++) {
    if (mn[i] != LLONG_MAX / 3) {
      ans.push_back(mn[i]);
    }
  }
  std::sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}