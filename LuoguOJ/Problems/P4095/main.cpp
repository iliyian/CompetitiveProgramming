// date: 2024-08-15 12:24:28
// tag: 二进制优化多重背包，前后缀背包

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> l(n + 1), r(n + 1);
  std::vector<int> w = {0}, v = {0};
  for (int i = 1; i <= n; i++) {
    int W, V, k;
    std::cin >> W >> V >> k;
    l[i] = w.size();
    for (int j = 0; (1 << j) < k; j++) {
      w.push_back((1 << j) * W);
      v.push_back((1 << j) * V);
      k -= 1 << j;
    }
    if (k) {
      w.push_back(k * W);
      v.push_back(k * V);
    }
    r[i] = w.size() - 1;
  }
  int len = w.size() - 1;
  std::vector<std::vector<int>> f(len + 2, std::vector<int>(1001)), g(len + 2, std::vector<int>(1001));
  for (int i = 1; i <= len; i++) {
    std::copy(f[i - 1].begin(), f[i - 1].end(), f[i].begin());
    for (int j = 1000; j >= w[i]; j--) {
      f[i][j] = std::max(f[i][j], f[i][j - w[i]] + v[i]);
    }
  }
  for (int i = len; i >= 1; i--) {
    std::copy(g[i + 1].begin(), g[i + 1].end(), g[i].begin());
    for (int j = 1000; j >= w[i]; j--) {
      g[i][j] = std::max(g[i][j], g[i][j - w[i]] + v[i]);
    }
  }
  int q;
  std::cin >> q;
  assert(q <= 35000);
  while (q--) {
    int d, e;
    std::cin >> d >> e;
    d++;
    int ans = 0;
    for (int i = 0; i <= e; i++) {
      ans = std::max(ans, f[l[d] - 1][i] + g[r[d] + 1][e - i]);
    }
    std::cout << ans << '\n';
  }

  return 0;
}