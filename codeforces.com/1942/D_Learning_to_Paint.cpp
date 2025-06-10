// date: 2025-04-22 22:57:11
// tag: 比较清奇的状态表示方式：可以不是一个值而是一些值。然后就是比较清奇的最值队列性质优化dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<std::array<std::vector<int>, 2>> f(n + 2);
  f[0][0] = {0};
  for (int i = 1; i <= n + 1; i++) {
    f[i][0] = f[i - 1][0];
    for (auto j : f[i - 1][1]) f[i][0].push_back(j);
    std::sort(f[i][0].begin(), f[i][0].end(), std::greater<>());
    while (f[i][0].size() > k) f[i][0].pop_back();
    if (i == n + 1) break;

    std::vector<int> pos(i);
    std::priority_queue<std::array<int, 2>> q;
    for (int j = 0; j <= i - 1; j++) {
      q.push({f[j][0].front() + a[j + 1][i], j});
    }
    for (int j = 0; j < k; j++) {
      if (q.empty()) break;
      auto [v, id] = q.top(); q.pop();
      f[i][1].push_back(v);
      if (pos[id] + 1 != f[id][0].size()) {
        pos[id]++;
        q.push({f[id][0][pos[id]] + a[id + 1][i], id});
      }
    }
  }
  for (auto i : f[n + 1][0]) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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