#include <bits/stdc++.h>
#define int long long

constexpr int N = 2000;
std::vector<int> d(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  int ansl = 1, ansr = 1, ans = 0;
  std::vector<int> le(n + 1), ge(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += i - 1 - query(a[i]);
    add(a[i], 1);
  }
  int ini = ans;
  // std::cerr << ans << '\n';
  for (int r = 1; r <= n; r++) {
    for (int l = 1; l < r; l++) {
      le[l] += a[r] < a[l];
      ge[l] += a[r] > a[l];
      // std::cerr << l << ' ' << r << ' ' << le[l] << ' ' << ge[l] << '\n';
      // int t = ge;
      if (ans > ini - le[l] + ge[l]) {
        ans = ini - le[l] + ge[l];
        ansl = l, ansr = r;
      }
    }
  }
  std::cout << ansl << ' ' << ansr << '\n';
  // std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    add(a[i], -1);
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