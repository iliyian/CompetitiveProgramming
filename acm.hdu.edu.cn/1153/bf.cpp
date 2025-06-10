#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, u, k, hq;
  std::cin >> n >> u >> k >> hq;
  std::vector<std::array<int, 4>> a(n + 1);
  std::vector<int> mx(n + 2);
  std::vector<int> t(62);
  int cu = u;
  for (int i = 1; i <= 61; i++) {
    // t[i] = t[i - 1] + cu;
    t[i] = cu;
    cu /= 2;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][1] >> a[i][0];
    a[i][2] = i;
    a[i][3] = 0;
  }
  int ans = 0;
  while (hq > 0) {
    int mx = -1, mxa = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][0] <= 0 || a[i][3] >= k) continue;
      if (mx == -1 || a[i] < a[mx]) {
        mx = i;
      }
    }
    if (mx == -1) break;
    a[mx][3]++;
    if (a[mx][3] > k) {
      assert(false);
      break;
    }
    a[mx][0] -= t[a[mx][3]];
    for (int i = 1; i <= n; i++) {
      if (a[i][0] <= 0) continue;
      cnt++;
      mxa = std::max(mxa, a[i][1]);
    }
    if (cnt == 0) break;
    hq -= mxa;
  }
  for (int i = 1; i <= n; i++) {
    ans += a[i][0] <= 0;
  }
  std::cout << ans << '\n';
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