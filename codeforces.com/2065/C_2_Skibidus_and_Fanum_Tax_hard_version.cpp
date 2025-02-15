#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 2);
  a[n + 1] = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> b(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::sort(b.begin() + 1, b.end());
  for (int i = n; i >= 1; i--) {
    int l = 1, r = m, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (b[mid] - a[i] <= a[i + 1]) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    if (ans == -1) {
      if (a[i] > a[i + 1]) {
        std::cout << "NO\n";
        return;
      }
    } else {
      if (a[i] > a[i + 1]) {
        a[i] = b[ans] - a[i];
      } else {
        a[i] = std::max(a[i], b[ans] - a[i]);
      }
    }
  }
  std::cout << "YES\n";
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