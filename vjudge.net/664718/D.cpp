#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));

  std::vector<int> vec = {INT_MIN};
  auto id = [&](int x) {return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();};

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      vec.push_back(a[i][j]);
    }
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  int len = vec.size() - 1;
  std::vector<std::vector<int>> px(len + 1), py(len + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      px[id(a[i][j])].push_back(i);
      py[id(a[i][j])].push_back(j);
    }
  }
  int ans = 0;
  for (int i = 1; i <= len; i++) {
    int sumx = 0, sumy = 0;
    std::sort(px[i].begin(), px[i].end());
    std::sort(py[i].begin(), py[i].end());
    for (int j = 0; j < px[i].size(); j++) {
      ans += j * px[i][j] - sumx;
      sumx += px[i][j];
    }
    for (int j = 0; j < py[i].size(); j++) {
      ans += j * py[i][j] - sumy;
      sumy += py[i][j];
    }
  }
  std::cout << ans * 2 << '\n';

  return 0;
}