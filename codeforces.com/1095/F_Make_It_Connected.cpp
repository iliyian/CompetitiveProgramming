// date: 2025-03-07 18:01:25
// tag: 明显人们的平均水平提高了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  int mni = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] < a[mni]) {
      mni = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != mni) {
      q.push({a[i] + a[mni], i, mni});
    }
  }
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    q.push({w, x, y});
  }
  int ans = 0, cnt = n - 1;
  while (!q.empty()) {
    auto [w, x, y] = q.top(); q.pop();
    if (merge(x, y)) {
      ans += w;
      if (!--cnt) {
        break;
      }
    }
  }
  std::cout << ans << '\n';
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