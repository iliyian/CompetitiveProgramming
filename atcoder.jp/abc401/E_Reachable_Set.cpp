#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  std::set<int> s;
  int cnt = 0;
  for (int k = 1; k <= n; k++) {
    s.erase(k);
    cnt++;
    for (int v : g[k]) {
      if (v < k) {
        if (merge(v, k)) {
          cnt--;
        }
      } else {
        s.insert(v);
      }
    }
    if (cnt != 1) {
      std::cout << -1 << '\n';
    } else {
      std::cout << s.size() << '\n';
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