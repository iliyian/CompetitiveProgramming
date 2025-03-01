// date: 2024-09-27 16:59:38
// tag: 双向逆序对，离散化

#include <bits/stdc++.h>
#define int long long

std::vector<double> vec;
int id(double x) {
  return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
};

signed main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(n + 1), y(n + 1), v(n + 1);
  std::vector<double> xt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i] >> v[i];
    xt[i] = x[i] + v[i] * std::sqrt(2 * y[i] / 9.8);
    vec.push_back(x[i]);
    vec.push_back(y[i]);
    vec.push_back(xt[i]);
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  int len = vec.size();
  std::vector<std::vector<std::tuple<int, double, int>>> a(len + 1);
  std::set<int> vis;
  std::vector<int> d(len + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i <= len; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    a[id(y[i])].push_back({x[i], xt[i], i});
    vis.insert(id(y[i]));
  }
  std::vector<int> ans(n + 1);
  for (auto &y : vis) {
    std::sort(a[y].begin(), a[y].end());
    for (int t = 0; t < 2; t++) {
      for (int i = 0; i < a[y].size(); i++) {
        auto &[x, xt, idx] = a[y][i];
        int cnt = (t ? query(id(xt)) : i - query(id(xt) - 1));
        ans[idx] += cnt;
        add(id(xt), 1);
      }
      for (auto &[x, xt, idx] : a[y]) {
        add(id(xt), -1);
      }
      std::reverse(a[y].begin(), a[y].end());
    }
  }
  std::vector<int> b(n + 1), f(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    f[i] = std::min(b[i], ans[i]);
    sum += ans[i];
  }
  std::sort(f.begin() + 1, f.end(), std::greater<>());
  for (int i = 1; i <= m; i++) {
    sum -= f[i];
  }
  std::cout << sum << '\n';
  return 0;
}