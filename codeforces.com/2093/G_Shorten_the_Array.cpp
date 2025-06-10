#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int tot = 1;
  std::vector<std::array<int, 2>> tr(n << 5);
  std::vector<int> mx(n << 5);
  auto insert = [&](int x, int id) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!tr[u][idx]) tr[u][idx] = ++tot;
      u = tr[u][idx];
      mx[u] = std::max(mx[u], id);
    }
  };
  auto query = [&](int x, int k) {
    int u = 1;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1, idk = k >> i & 1;
      if (!u) return ans;
      if (idk) {
        if (!tr[u][idx ^ 1]) return ans;
        u = tr[u][idx ^ 1];
      } else {
        if (tr[u][idx ^ 1]) {
          ans = std::max(ans, mx[tr[u][idx ^ 1]]);
        }
        u = tr[u][idx];
      }
    }
    return ans;
  };
  if (k == 0) {
    std::cout << 1 << '\n';
    return;
  }
  k--;
  int res = n + 1;
  for (int i = 1; i <= n; i++) {
    int ans = query(a[i], k);
    if (ans) {
      res = std::min(res, i - ans + 1);
    }
    insert(a[i], i);
  }
  std::cout << (res == n + 1 ? -1 : res) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}