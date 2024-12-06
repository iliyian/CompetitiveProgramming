#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> x(n + 1), y(n + 1);
  std::vector<int> vec = {INT_MIN};
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
    vec.push_back(x[i]);
    vec.push_back(y[i]);
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
    return x[u] + y[u] < x[v] + y[v];
  });
  // std::sort(vec.begin(), vec.end());
  // int len = vec.size() - 1;
  // std::vector<int> d(len + 1);
  // auto add = [&](int x, int c) {
  //   for (int i = x; i <= len; i += i & -i) d[i] += c;
  // };
  // auto query = [&](int x) {
  //   int ans = 0;
  //   for (int i = x; i > 0; i -= i & -i) ans += d[i];
  //   return ans;
  // };
  // int cnt0 = 0, cnt1 = 0;
  // std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
  //   return std::tie(x[u], y[u]) < std::tie(x[v], y[v]);
  // });
  // for (int i = 1; i <= n; i++) {
  //   cnt0 += (i - 1) * 2 - query(id(x[p[i]]));
  //   add(id(x[p[i]]), 1);
  //   cnt0 += (i - 1) * 2 + 1 - query(id(y[p[i]]));
  //   add(id(y[p[i]]), 1);
  // }
  // for (int i = 1; i <= n; i++) {
  //   add(id(x[p[i]]), -1);
  //   add(id(y[p[i]]), -1);
  // }
  // // for (int i = 1; i <= n; i++) {
  // //   std::cout << p[i] << " \n"[i == n];
  // // }
  
  // std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
  //   return std::tie(y[u], x[u]) < std::tie(y[v], x[v]);
  // });
  // // for (int i = 1; i <= n; i++) {
  // //   std::cout << p[i] << " \n"[i == n];
  // // }
  // for (int i = 1; i <= n; i++) {
  //   cnt1 += (i - 1) * 2 - query(id(x[p[i]]));
  //   add(id(x[p[i]]), 1);
  //   cnt1 += (i - 1) * 2 + 1 - query(id(y[p[i]]));
  //   add(id(y[p[i]]), 1);
  // }
  // for (int i = 1; i <= n; i++) {
  //   add(id(x[p[i]]), -1);
  //   add(id(y[p[i]]), -1);
  // }
  // // std::cout << cnt1 << ' ' << cnt0 << '\n';
  // if (cnt1 > cnt0) {
  //   std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
  //     return std::tie(x[u], y[u]) < std::tie(x[v], y[v]);
  //   });
  // }
  for (int i = 1; i <= n; i++) {
    std::cout << x[p[i]] << ' ' << y[p[i]] << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}