// date: 2024-07-18 09:08:59
// tag: 单调队列优化dp

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<int> a(m + 1), b(m + 1), t(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i] >> b[i] >> t[i];
  }

  std::deque<int> q;
  std::vector<std::vector<int>> f(2, std::vector<int>(n + 1));

  for (int i = 1; i <= n; i++) {
    f[1][i] = b[1] - std::abs(a[1] - i);
  }

  int cur = 1;
  for (int i = 2; i <= m; i++) {
    int ds = (t[i] - t[i - 1]) * d, k = 1;
    cur ^= 1;
    while (!q.empty()) {
      q.pop_back();
    }
    for (int j = 1; j <= n; j++) {
      while (!q.empty() && q.front() < j - ds) {
        q.pop_front();
      }
      while (k <= std::min(n, j + ds)) {
        while (!q.empty() && f[cur ^ 1][q.back()] <= f[cur ^ 1][k]) {
          q.pop_back();
        }
        q.push_back(k++);
      }
      f[cur][j] = f[cur ^ 1][q.front()] + b[i] - std::abs(a[i] - j);
    }
  }
  std::cout << *std::max_element(f[cur].begin() + 1, f[cur].end()) << '\n';

  return 0;
}