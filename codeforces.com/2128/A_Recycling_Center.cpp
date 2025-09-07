#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::ranges::sort(a);
  int ans = 0;
  for (int i = 0;; i++) {
    bool f = false;
    for (int j = n - 1; j >= 0; j--) {
      if (a[j] <= c && a[j]) {
        f = true;
        a[j] = 0;
        break;
      }
    }
    if (!f) {
      break;
    }
    for (int j = 0; j < n; j++) {
      a[j] *= 2;
    }
  }
  for (int i = 0; i < n; i++) {
    ans += a[i] > c;
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