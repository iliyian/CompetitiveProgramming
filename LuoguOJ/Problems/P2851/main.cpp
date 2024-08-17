// date: 2024-08-15 13:02:07
// tag: 二进制优化多重背包，完全背包，货币问题

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, t;
  std::cin >> n >> t;
  std::vector<int> v(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::vector<int> g(t * 2, INT_MAX);
  g[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = v[i]; j <= t * 2 - 1; j++) {
      g[j] = std::min(g[j], g[j - v[i]] + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; (1 << j) < c[i]; j++) {
      v.push_back((1 << j) * v[i]);
      c.push_back(1 << j);
      c[i] -= 1 << j;
    }
  }
  int len = v.size() - 1;
  std::vector<int> f(t * 2, INT_MAX);
  f[0] = 0;
  for (int i = 1; i <= len; i++) {
    for (int j = t * 2 - 1; j >= v[i]; j--) {
      f[j] = std::min(f[j], f[j - v[i]] + c[i]);
    }
  }
  int ans = INT_MAX;
  for (int i = t; i < t * 2; i++) {
    ans = std::min(ans, f[i] + g[i - t]);
  }
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';

  return 0;
}