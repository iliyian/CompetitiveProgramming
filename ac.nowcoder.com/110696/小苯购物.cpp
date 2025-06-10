#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int a[3], b[3];
  for (int i = 0; i < 3; i++) {
    std::cin >> a[i] >> b[i];
  }
  int p[] = {0, 1, 2}, ans = n;
  do {
    int m = n;
    for (int i = 0; i < 3; i++) {
      if (m >= a[p[i]]) {
        m -= b[p[i]];
      }
    }
    ans = std::min(ans, m);
  } while (std::next_permutation(p, p + 3));
  std::cout << std::max(ans, 0ll) << '\n';
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