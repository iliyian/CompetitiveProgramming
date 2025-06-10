#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::pair<int, int>>> c(m + 1, std::vector<std::pair<int, int>>(n + 1));
  std::vector<std::vector<int>> w(n + 1, std::vector<int>(m + 1));
  std::vector<int> in(n + 1, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      std::cin >> x;
      c[j][i] = {x, i};
    }
    for (int j = 1; j <= m; j++) {
      std::cin >> w[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    std::sort(c[i].begin() + 1, c[i].end());
  }
  std::vector<int> cur(m + 1, 1);
  std::queue<int> q;
  auto check = [&](int x) {
    while (cur[x] <= n) {
      auto [r, id] = c[x][cur[x]];
      if (r <= a[x]) {
        if (!--in[id]) {
          q.push(id);
        }
        cur[x]++;
      }
      else break;
    }
  };
  for (int i = 1; i <= m; i++) {
    check(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    // std::cerr << u << '\n';
    for (int i = 1; i <= m; i++) {
      a[i] += w[u][i];
    }
    for (int i = 1; i <= m; i++) {
      check(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (in[i]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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