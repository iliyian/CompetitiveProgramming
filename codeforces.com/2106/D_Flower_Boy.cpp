#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::vector<int> pre(m + 2), suf(m + 2);
  pre[0] = -1, suf[m + 1] = m + 1;
  for (int r = 1, l = 1; r <= m; r++) {
    while (l <= n && a[l] < b[r]) {
      l++;
    }
    if (l <= n) {
      pre[r] = l;
      l++;
    } else {
      break;
    }
  }
  for (int r = m, l = n; r >= 1; r--) {
    while (l >= 1 && a[l] < b[r]) {
      l--;
    }
    if (l >= 1) {
      suf[r] = l;
      l--;
    } else {
      break;
    }
  }
  // for (int i = 1; i <= m; i++) {
  //   std::cerr << pre[i] << ' ' << suf[i] << '\n';
  // }
  int ans = LLONG_MAX;
  for (int i = 1; i <= m - 1; i++) {
    if (i + 1 <= m) {
      if (pre[i] && suf[i + 1] && pre[i] < suf[i + 1]) {
        std::cout << 0 << '\n';
        return;
      }
    }
    if (i >= 2 && i <= m - 1) {
      if (pre[i - 1] && suf[i + 1] && pre[i - 1] < suf[i + 1]) {
        ans = std::min(ans, b[i]);
      }
    }
  }
  if (suf[1] || pre[m]) {
    ans = 0;
  }
  if (suf[2]) {
    ans = std::min(ans, b[1]);
  }
  if (pre[m - 1]) {
    ans = std::min(ans, b[m]);
  }
  std::cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
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