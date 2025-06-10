#include <bits/stdc++.h>
#define int long long

int dx[] = {1, 0, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 0, -1, -1};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> pa(n + 1), siz(n + 1, 1), ans(n + 1);
  std::map<std::pair<int, int>, int> id;
  int tot = 0;
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    ans[y] += ans[x];
    pa[x] = y;
    return true;
  };
  auto add = [&](int x, int y) {
    id[{x, y}] = ++tot;
    pa[tot] = tot;
    ans[tot] = 6;
  };
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      add(x, y);
      for (int d = 0; d < 6; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (id.count({xx, yy})) {
          auto z = find(find, id[{xx, yy}]);
          cnt[z]++;
        }
      }
      int sum = 0;
      for (auto [k, v] : cnt) {
        sum += v * 2;
      }
      for (auto [k, v] : cnt) {
        merge(k, tot);
      }
      ans[find(find, tot)] -= sum;
      cnt.clear();
    } else {
      std::cout << ans[find(find, id[{x, y}])] << '\n';
    }
  }
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