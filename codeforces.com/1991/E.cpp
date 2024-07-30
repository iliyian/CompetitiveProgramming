// date: 2024-07-29 14:44:34
// tag: 二分图

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::queue<int> q;
  std::vector<int> dis(n + 1, -1);
  q.push(1);
  dis[1] = 0;
  bool f = true;
  std::vector<int> l, r;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (dis[x] % 2 == 0) {
      l.push_back(x);
    } else {
      r.push_back(x);
    }
    for (int y : g[x]) {
      if (dis[y] == -1) {
        q.push(y);
        dis[y] = dis[x] + 1;
      } else if ((dis[y] - dis[x]) % 2 == 0) {
        f = false;
      }
    }
  }
  if (!f) {
    std::cout << "Alice" << std::endl;
    for (int i = 1; i <= n; i++) {
      std::cout << 1 << ' ' << 2 << std::endl;
      int j, x;
      std::cin >> j >> x;
    }
  } else {
    std::cout << "Bob" << std::endl;
    for (int i = 1; i <= n; i++) {
      int a, b;
      std::cin >> a >> b;
      if (!l.empty() && !r.empty()) {
        if (a == 1 || b == 1) {
          std::cout << l.back() << ' ' << 1 << std::endl;
          l.pop_back();
        } else {
          std::cout << r.back() << ' ' << 2 << std::endl;
          r.pop_back();
        }
      } else if (l.empty()) {
        int col = (a == 1 ? b : a);
        std::cout << r.back() << ' ' << col << std::endl;
        r.pop_back();
      } else {
        int col = (a == 2 ? b : a);
        std::cout << l.back() << ' ' << col << std::endl;
        l.pop_back();
      }
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}