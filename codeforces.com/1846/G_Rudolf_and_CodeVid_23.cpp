// date: 2025-04-11 16:27:19
// tag: 过于典型，没啥可说的状压最短路

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  int from = 0;
  for (auto i : str) from = from * 2 + (i == '1');
  std::vector<int> w(m + 1), s(m + 1), t(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> w[i];
    std::string st;
    std::cin >> st;
    for (auto j : st) {
      s[i] = s[i] * 2 + (j == '1');
    }
    std::cin >> st;
    for (auto j : st) {
      t[i] = t[i] * 2 + (j == '1');
    }
  }
  // std::cerr << from << '\n';
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::vector<int> dis((1 << n), LLONG_MAX / 3);
  q.push({dis[from] = 0, from});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (int i = 1; i <= m; i++) {
      auto v = (u & (~s[i])) | t[i];
      if (dis[v] > dis[u] + w[i]) {
        q.push({dis[v] = dis[u] + w[i], v});
      }
    }
  }
  std::cout << (dis[0] == LLONG_MAX / 3 ? -1 : dis[0]) << '\n';
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