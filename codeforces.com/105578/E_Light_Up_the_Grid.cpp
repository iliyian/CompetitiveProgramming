#include <bits/stdc++.h>
#define int long long

void solve() {
  int Q;
  std::cin >> Q;
  int a[4] {};
  for (int i = 0; i < 4; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> op(4);
  for (int i = 0; i < 4; i++) {
    op[0].push_back(1ll << i);
  }
  op[1].push_back(3);
  op[1].push_back(12);
  op[2].push_back(5);
  op[2].push_back(10);
  op[3].push_back(15);

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::vector<int> dis(1ll << 16, LLONG_MAX / 3);
  q.push({dis[0] = 0, 0});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (int i = 0; i < 4; i++) {
      for (int val : op[i]) {
        int v = 0;
        for (int j = 0; j < 16; j++) {
          if (u >> j & 1) {
            v |= 1ll << (j ^ val);
          }
        }
        if (dis[v] > dis[u] + a[i]) {
          dis[v] = dis[u] + a[i];
          q.push({dis[v], v});
        }
        v |= 1ll << (15 ^ val);
        if (dis[v] > dis[u] + a[i]) {
          dis[v] = dis[u] + a[i];
          q.push({dis[v], v});
        }
      }
    }
  }
  while (Q--) {
    int n, u = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      int v = 0;
      for (int j = 0; j < 4; j++) {
        char ch;
        std::cin >> ch;
        v |= (ch - '0') << j;
      }
      u |= 1ll << v;
    }
    std::cout << dis[u] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}