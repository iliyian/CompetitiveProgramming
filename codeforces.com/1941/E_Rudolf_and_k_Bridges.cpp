#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k, d;
  std::cin >> n >> m >> k >> d;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1;
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    std::deque<int> q;
    q.push_back(1);
    for (int j = 2; j <= m; j++) {
      while (!q.empty() && q.front() < j - d - 1) q.pop_front();
      f[i][j] = f[i][q.front()] + a[i][j] + 1;
      while (!q.empty() && f[i][q.back()] >= f[i][j]) {
        q.pop_back();
      }
      q.push_back(j);
    }
  }
  std::vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + f[i][m];
    // std::cerr << f[i][m] << ' ';
  }
  // std::cerr << '\n';
  int ans = LLONG_MAX / 3;
  for (int i = k; i <= n; i++) {
    ans = std::min(ans, s[i] - s[i - k]);
  }
  std::cout << ans << '\n';
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