#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> _in(n + 1);
  for (int i = 1; i <= m; i++) {
    int id, k;
    std::cin >> id >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      std::cin >> x;
      g[id].push_back(x);
      _in[x]++;
    }
  }
  auto check = [&](int mid) -> bool {
    std::queue<int> q;
    q.push(1);
    auto f = a;
    auto in = _in;
    f[1] -= mid;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : g[u]) {
        if (f[u] < 0) {
          f[v] -= -f[u];
        }
        if (!--in[v]) {
          q.push(v);
        }
      }
    }
    // if (mid == 21) {
    //   for (int i = 1; i <= n; i++) {
    //     std::cout << f[i] << ' ';
    //   }
    //   std::cout << '\n';
    //   for (int i = 1; i <= n; i++) {
    //     std::cout << in[i] << ' ';
    //   }
    //   std::cout << '\n';
    // }
    for (int i = 2; i <= n; i++) {
      if (g[i].empty() && f[i] < 0) {
        return false;
      }
    }
    return true;
  };
  if (n == 1) {
    std::cout << a[1] << '\n';
    return;
  }
  int l = a[1], r = 1e16, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}