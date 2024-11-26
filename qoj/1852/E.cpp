#include <bits/stdc++.h>
#define int long long

std::vector<int> dis(1 << 16, INT_MAX), vis(1 << 16, 0);

int a0, a1, a2, a3;

std::vector<int> op = {1, 2, 4, 8, 3, 12, 5, 10, 15};
std::vector<int> cost;

int nxt(int u, int k) {
  int v = 0;
  for (int i = 0; i < 16; i++) {
    if (u >> i & 1) {
      // if ((i ^ k) != 15) {
        v ^= 1 << (i ^ k);
      // }
    }
  }
  return v;
}

void solve() {
  int n;
  std::cin >> n;
  int u = 0;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    char a, b, c, d;
    std::cin >> a >> b >> c >> d;
    a -= '0', b -= '0', c -= '0', d -= '0';
    int x = a * 1 + b * 2 + c * 4 + d * 8;
    u ^= 1 << x;
  }
  // std::cout << u << '\n';
  std::cout << dis[u] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  std::cin >> a0 >> a1 >> a2 >> a3;
  cost = {a0, a0, a0, a0, a1, a1, a2, a2, a3, 0};

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({dis[0] = 0, 0});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = 0; i < 9; i++) {
      int v = nxt(u, op[i]);
      if (dis[v] > dis[u] + cost[i]) {
        dis[v] = dis[u] + cost[i];
        q.push({dis[v], v});
      }
      int vv = v ^ (1 << (15 ^ op[i]));
      if (dis[vv] > dis[u] + cost[i]) {
        dis[vv] = dis[u] + cost[i];
        q.push({dis[vv], vv});
      }
    }
  }
  

  while (t--) {
    solve();
  }
  return 0;
}