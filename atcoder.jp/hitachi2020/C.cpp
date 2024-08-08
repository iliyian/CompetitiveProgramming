// date: 2024-08-02 12:18:05
// tag: 构造，树，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> a, b, c(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    c[u] = c[p] ^ 1;
    if (c[u]) a.push_back(u);
    else b.push_back(u);
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::vector<int> ans(n + 1);
  if (a.size() <= n / 3) {
    int x = 0, y = 0;
    for (int i = 3; i <= n; i += 3) {
      (x < a.size() ? ans[a[x++]] : ans[b[y++]]) = i;
    }
    for (int i = 1; i <= n; i++) {
      if (i % 3) {
        ans[b[y++]] = i;
      }
    }
  } else if (b.size() <= n / 3) {
    int x = 0, y = 0;
    std::swap(a, b);
    for (int i = 3; i <= n; i += 3) {
      (x < a.size() ? ans[a[x++]] : ans[b[y++]]) = i;
    }
    for (int i = 1; i <= n; i++) {
      if (i % 3) {
        ans[b[y++]] = i;
      }
    }
  } else {
    int p1 = 1, p2 = 2, p3 = 3;
    for (int i = 1; i <= n; i++) {
      if (c[i]) {
        if (p1 <= n) ans[i] = p1, p1 += 3;
        else ans[i] = p3, p3 += 3;
      } else {
        if (p2 <= n) ans[i] = p2, p2 += 3;
        else ans[i] = p3, p3 += 3;
      }
    }
  }
  // for (auto i : a) {
  //   std::cout << i << ' ' << ans[i] % 3 << ' ' << c[i] << '\n';
  // }
  // std::cout << '\n';
  // for (auto i : b) {
  //   std::cout << i << ' ' << ans[i] % 3 << ' ' << c[i] << '\n';
  // }
  // std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }

  return 0;
}