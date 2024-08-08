// date: 2024-08-04 09:35:25
// tag: 反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  std::vector<int> a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i] >> c[i];
  }
  std::vector<int> lst(n + 1);
  std::iota(lst.begin() + 1, lst.end(), 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    lst[y] = std::max(lst[y], x);
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    g[lst[i]].push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    while (k < a[i]) {
      if (q.empty()) {
        std::cout << -1 << '\n';
        return;
      }
      int u = q.top(); q.pop();
      k++;
      ans -= u;
    }
    k += b[i];
    for (int v : g[i]) {
      q.push(c[v]);
      ans += c[v];
      k--;
    }
  }
  while (k < 0) {
    if (q.empty()) {
      std::cout << -1 << '\n';
      return;
    }
    int u = q.top(); q.pop();
    k++;
    ans -= u;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  solve();

  return 0;
}