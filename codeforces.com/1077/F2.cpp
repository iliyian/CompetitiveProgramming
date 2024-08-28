// date: 2024-08-18 15:01:55
// tag: 单调队列优化dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F2.out", "w", stdout);

  int n, k, m;
  std::cin >> n >> k >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  // std::vector<std::vector<int>> g(n + 1, std::vector<int>(m + 1, LLONG_MIN));
  // g[0][0] = 0;
  // std::deque<int> q;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= std::min(i,  m); j++) {
  //     for (int t = std::max(0ll, i - k); t <= i - 1; t++) {
  //       g[i][j] = std::max(g[i][j], g[t][j - 1] + a[i]);
  //     }
  //   }
  // }
  // int realans = -1;
  // for (int i = n - k + 1; i <= n; i++) {
  //   realans = std::max(realans, g[i][m]);
  // }
  // std::cout << realans << '\n';

  std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, LLONG_MIN));
  f[0][0] = 0;
  for (int j = 0; j < m; j++) {
    std::deque<int> q;
    for (int i = j; i < n; i++) {
      while (!q.empty() && q.front() <= i - k) {
        q.pop_front();
      }
      while (!q.empty() && f[q.back()][j] < f[i][j]) {
        q.pop_back();
      }
      q.push_back(i);
      f[i + 1][j + 1] = f[q.front()][j] + a[i + 1];
    }
  }
  int ans = -1;
  for (int i = n - k + 1; i <= n; i++) {
    ans = std::max(ans, f[i][m]);
  }
  std::cout << ans << '\n';

  return 0;
}