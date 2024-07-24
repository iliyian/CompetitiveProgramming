#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2)),
    f(n + 2, std::vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    f[i][m] = a[i][m];
    f[i][1] = a[i][1];
  }
  for (int i = 1; i <= m; i++) {
    f[n][i] = a[n][i];
    f[1][i] = a[1][i];
  }

  std::queue<std::tuple<int, int>> q;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if ((!dx || !dy) && (dy || dx)) {

        }
      }
    }
  }

  std::vector<int> ans(k + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f[i][j] <= k) {
        ans[f[i][j]]++;
      }
    }
  }
  int cur = n * m;
  for (int i = 1; i <= k; i++) {
    cur -= ans[i];
    std::cout << cur << '\n';
  }

  return 0;
}