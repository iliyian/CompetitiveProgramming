// date: 2024-08-23 17:37:31
// tag: 竞赛图找三元环模板

#include <bits/stdc++.h>
#include <stack>
// #define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  std::vector<int> ins(n), ring, vis(n);
  std::stack<int> s;
  bool done = false;
  auto dfs = [&](auto self, int u) -> void {
    if (done) return;
    if (ins[u]) {
      done = true;
      while (true) {
        int x = s.top(); s.pop();
        ins[x] = false;
        ring.push_back(x);
        if (x == u) break;
      }
      return;
    }
    if (vis[u]) return;
    ins[u] = vis[u] = true;
    s.push(u);
    for (int v = 0; v < n; v++) {
      if (a[u][v] == '1') {
        self(self, v);
      }
    }
    s.pop();
    ins[u] = false;
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(dfs, i);
    }
  }
  if (!done) {
    std::cout << -1 << '\n';
    return 0;
  }
  for (int i = ring.size() - 2; i >= 1; i--) {
    int y = ring[i + 1], z = ring[i];
    if (a[z][ring[0]] == '1') {
      std::cout << ring[0] + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
      return 0;
    }
  }

  return 0;
}