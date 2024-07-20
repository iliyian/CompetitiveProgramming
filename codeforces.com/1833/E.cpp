// date: 2024-07-19 11:07:18
// tag: dsu

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pa(n + 1), in(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
  };
  std::set<std::pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (s.count({x, i})) continue;
    in[x]++, in[i]++;
    s.insert({x, i});
    s.insert({i, x});
    merge(x, i);
  }
  int mx = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i) {
      mx++;
    }
    if (in[i] == 1) {
      cnt++;
    }
  }
  std::cout << std::min(mx, mx - cnt / 2 + 1) << ' ' << mx << '\n';
}

signed main() {
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