#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, l, r;
  std::cin >> n >> k >> l >> r;
  std::vector<int> vec = {LLONG_MIN / 3}, a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  std::ranges::sort(vec);
  for (int i = 1; i <= n; i++) {
    a[i] = std::ranges::lower_bound(vec, a[i]) - vec.begin();
  }
  std::vector<int> d(n + 1), prv(n + 1);
  auto add = [&](int x, int c) {for (int i = x; i <= n; i += i & -i) d[i] += c;};
  auto query = [&](int x) {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (prv[a[i]]) {
      add(prv[a[i]], -1);
    } else {
      tot++;
    }
    prv[a[i]] = i;
    add(i, 1);
    int _l = 1, _r = i, L = -1, R = -1;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (tot - query(mid - 1) <= k) L = mid, _r = mid - 1;
      else _l = mid + 1;
    }
    _l = 1, _r = i;
    while (_l <= _r) {
      int mid = (_l + _r) / 2;
      if (tot - query(mid - 1) >= k) R = mid, _l = mid + 1;
      else _r = mid - 1;
    }
    if (L != -1 && R != -1) {
      // std::cerr << i << ' ' << L << ' ' << R << '\n';
      L = std::max(L, i - r + 1);
      R = std::min(R, i - l + 1);
      ans += std::max(0ll, R - L + 1);
    }
  }
  std::cout << ans << '\n';
  // std::cerr << '\n';
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