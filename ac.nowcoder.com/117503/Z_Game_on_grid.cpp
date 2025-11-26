#include <bits/stdc++.h>
#define int long long

int dx[] = {1, 0}, dy[] = {0, 1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto work = [&]() {
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
    auto dfs = [&](auto self, int x, int y) -> void {
      for (int i = 0; i < 2; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (in(xx, yy)) {
          if ()
        }
      }
    }
  };
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