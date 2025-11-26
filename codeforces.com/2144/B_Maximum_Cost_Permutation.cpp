#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int l = 0, r = 0, s = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == 0) {
      s++;
    }
  }
  if (s == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        a[i] = n * (n + 1) / 2 - std::accumulate(a.begin(), a.end(), 0ll);
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      if (l == 0) l = i;
      r = i;
    }
  }
  if (l == r) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << r - l + 1 << '\n';
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