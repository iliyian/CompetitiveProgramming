#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), d(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  std::vector<int> pos(n + 1), b(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    pos[b[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    ans[a[i]] = pos[a[i]] - 1 - query(pos[a[i]]) + i - 1;
    add(pos[a[i]], 1);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
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