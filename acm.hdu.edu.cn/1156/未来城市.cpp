#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> e;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    e.push_back({w, x, y});
  }
  std::sort(e.begin(), e.end(), std::greater<>());
  std::vector<int> pa(n + 1), siz(n + 1, 1), cnt(n + 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x != y) {
      if (siz[x] > siz[y]) std::swap(x, y);
      if (cnt[x] < siz[x] || cnt[y] < siz[y]) {
        pa[x] = y;
        siz[y] += siz[x];
        cnt[y] += cnt[x] + 1;
        return true;
      }
      return false;
    } else {
      if (cnt[x] == siz[x]) {
        return false;
      }
      cnt[x]++;
      return true;
    }
  };
  int ans = 0;
  for (auto [w, x, y] : e) {
    if (merge(x, y)) {
      ans += w;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}