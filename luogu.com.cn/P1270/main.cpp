// date: 2024-08-01 09:36:44
// tag: 树上泛化物品背包剪枝

#include <bits/stdc++.h>
// #define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int T;
  std::cin >> T;
  std::vector<std::vector<int>> f(2000, std::vector<int>(7000));
  std::vector<int> siz(2000);
  int tot = 0;
  auto dfs = [&](auto self) -> void {
    int rt = ++tot, x, y;
    std::cin >> x >> y;
    x <<= 1;
    if (y) {
      for (int i = x; i <= T; i++) {
        f[rt][i] = std::min((i - x) / 5, y);
      }
      siz[rt] = x + y * 5;
      return;
    }
    int l = tot + 1;
    self(self);
    int r = tot + 1;
    self(self);
    siz[rt] = siz[l] + siz[r] + x;
    // for (int i = x; i <= T; i++) {
    for (int i = x; i <= std::min(T, siz[rt]); i++) {
      for (int j = 0; j <= i - x; j++) {
        f[rt][i] = std::max(f[rt][i], f[l][j] + f[r][i - j - x]);
      }
    }
  };
  dfs(dfs);
  std::cout << f[1][T - 1];

  return 0;
}