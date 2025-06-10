#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> vec = {LLONG_MIN};
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    vec.push_back(a[i]);
    vec.push_back(b[i]);
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  int len = vec.size() - 1;
  // std::vector<std::vector<int>> g(len * 2 + 1);
  std::vector<std::set<int>> g(len * 2 + 1);
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  std::vector<int> deg(len * 2 + 1), pa(len * 2 + 1), siz(len * 2 + 1, 1);
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
  for (int i = 1; i <= n; i++) {
    a[i] = id(a[i]), b[i] = id(b[i]);
    g[a[i]].insert(b[i] + len);
    g[b[i] + len].insert(a[i]);
    deg[b[i] + len]++, deg[a[i]]++;
    if (merge(a[i], b[i] + len)) {
    }
  }
  int cnt = 0, s = -1, t = -1;
  for (int i = 1; i <= len * 2; i++) {
    if (deg[i] % 2 == 0) {
      cnt++;
    } else if (s == -1) {
      s = i;
    } else {
      t = i;
    }
  }
  if (siz[find(find, 1)] != len * 2 || (cnt != len * 2 - 2 && cnt != len * 2)) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  auto dfs = [&](auto self, int x) -> void {
    while (!g[x].empty()) {
      int net = *g[x].begin();
      g[x].erase(g[x].find(net));
      g[net].erase(g[net].find(x));
      std::cout << x << ' ';
      self(self, net);
    }
  };
  dfs(dfs, 1);
  std::cout << '\n';
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