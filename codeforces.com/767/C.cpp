// date: 2024-08-13 13:52:01
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  int rt = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x >> a[i];
    sum += a[i];
    if (!x) rt = i;
    else g[x].push_back(i);
  }
  if (sum % 3) {
    std::cout << -1 << '\n';
    return 0;
  }
  std::vector<int> f(n + 1), cnt1;;
  int dfncnt = 0;
  auto dfs = [&](auto self, int u) -> void {
    f[u] = a[u];
    for (int v : g[u]) {
      self(self, v);
      f[u] += f[v];
    }
    if (f[u] == sum / 3 && cnt1.size() <= 2 && u != rt) {
      cnt1.push_back(u);
      f[u] = 0;
    }
  };
  dfs(dfs, rt);
  if (cnt1.size() >= 2) {
    std::cout << cnt1[0] << ' ' << cnt1[1] << '\n';
    return 0;
  }
  std::cout << -1 << '\n';
  return 0;
}