#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = ch - '0';
    }
  }
  std::vector<std::vector<int>> l(n + 1), r(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i][j]) {
        r[i].push_back(j);
        l[j].push_back(i);
      } else {
        l[i].push_back(j);
        r[j].push_back(i);
      }
    }
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return l[x].size() < l[y].size();
  });
  for (int i = 1; i <= n; i++) {
    std::cout << p[i] << ' ';
  }
  // std::cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cout << l[p[i]].size() << ' ';
  // }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}