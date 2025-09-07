#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<int> s(n + 1), vec = {-1};
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    vec.push_back(s[i]);
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::ranges::sort(vec);
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  auto id = [&](int x) -> int {
    return std::ranges::lower_bound(vec, x) - vec.begin();
  };
  int nn = vec.size() - 1;
  std::vector<std::vector<int>> g(nn + 1);
  for (int i = 1; i <= n; i++) {
    g[id(s[i])].push_back(i);
  }
  int prv = -1;
  for (int lv = 1; lv <= nn; lv++) {
    bool f = true;
    int mx = 0;
    for (int i : g[lv]) {
      int sum = 0;
      for (int j = 1; j <= m; j++) {
        if (a[i][j] != -1) {
          sum += a[i][j];
        }
      }
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == -1) {
          a[i][j] = std::max(0ll, std::min(k, prv + 1 - sum));
          sum += a[i][j];
        }
      }
      if (sum <= prv) {
        std::cout << "No\n";
        return;
      }
      mx = std::max(mx, sum);
    }
    prv = mx;
  }
  std::cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << a[i][j] << ' ';
    }
    std::cout << '\n';
  }
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