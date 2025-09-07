#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  std::vector f(n + 1, std::vector<std::vector<int>>(n + 1));
  std::vector v(n + 1, std::vector<std::vector<std::pair<int, int>>>(n + 1));
  auto log2 = [&](int x) -> int {
    int y = 63 - __builtin_clzll(x);
    if ((1ll << y) == x)
      return y;
    return y + 1;
  };
  auto cost = [&](int l, int r, int mid) {
    return log2(a[r] - a[l - 1]) * std::min(a[r] - a[mid], a[mid] - a[l - 1]);
  };
  int tot = 0;
  auto unbalance = [&](int l, int r, int mid) {
    return std::abs(a[r] - a[mid] - a[mid] + a[l - 1]);
  };
  for (int i = 1; i <= n - 1; i++) {
    f[i][i + 1].push_back(cost(i, i + 1, i));
    v[i][i + 1].push_back({unbalance(i, i + 1, i), cost(i, i + 1, i)});
  }
  auto get = [&](int l, int r, int lim) {
    if (l == r)
      return 0ll;
    int ans = -1, ll = l, rr = r;
    auto &vv = v[l][r];
    r--;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (vv[mid - ll].first <= lim)
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    return ans == -1 ? LLONG_MAX / 3 : vv[ans - ll].second;
  };
  for (int len = 3; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      auto &ff = f[l][r];
      auto &vv = v[l][r];
      for (int mid = l; mid <= r - 1; mid++) {
        int lim = unbalance(l, r, mid);
        int v = cost(l, r, mid) + get(l, mid, lim) + get(mid + 1, r, lim);
        v = std::min(v, LLONG_MAX / 3);
        ff.push_back(v);
        vv.push_back({lim, v});
      }
      std::ranges::sort(vv);
      for (int i = 1; i < vv.size(); i++) {
        vv[i].second = std::min(vv[i].second, vv[i - 1].second);
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    std::cout << (f[1][n][i] >= LLONG_MAX / 3 ? -1 : f[1][n][i]) << ' ';
  }
  std::cout << '\n';
  // std::cerr << tot << '\n';
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