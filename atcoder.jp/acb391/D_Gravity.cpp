#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, w;
  std::cin >> n >> w;
  std::vector<std::vector<std::pair<int, int>>> a(w + 1);
  std::vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
    a[x[i]].push_back({y[i], i});
  }
  std::vector<int> ans(n + 1);
  int mindep = INT_MAX;
  for (int i = 1; i <= w; i++) {
    std::sort(a[i].begin(), a[i].end());
    mindep = std::min(mindep, (int)a[i].size());
  }
  // std::cerr << mindep << '\n';
  std::vector<int> maxh(mindep + 1);
  for (int i = 1; i <= mindep; i++) {
    for (int j = 1; j <= w; j++) {
      // assert(i <= a[j].size());
      maxh[i] = std::max(maxh[i], a[j][i - 1].first);
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int t, b;
    std::cin >> t >> b;
    auto p = std::lower_bound(a[x[b]].begin(), a[x[b]].end(), std::pair{y[b], b}) - a[x[b]].begin();
    // std::cerr << x[b] << ' ' << y[b] << '\n';
    // std::cerr << a[x[b]][p].first << '\n';
    if (p >= mindep) {
      std::cout << "Yes\n";
      continue;
    }
    // std::cerr << maxh[p + 1] << '\n';
    if (t < maxh[p + 1]) {
      std::cout << "Yes\n";
      continue;
    }
    std::cout << "No\n";
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