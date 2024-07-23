#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n + 1);
  for (int i = y; i <= x; i++) {
    a[i] = 1;
  }
  for (int i = y - 1; i >= 1; i--) {
    a[i] = ((y - i) & 1 ? -1 : 1);
  }
  for (int i = x + 1; i <= n; i++) {
    a[i] = ((x - i) & 1 ? -1 : 1);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';

  // int mx = -n, sum = 0;
  // for (int i = 1; i <= n; i++) {
  //   sum += a[i];
  //   mx = std::max(mx, sum);
  // }
  // sum = 0;
  // for (int i = 1; i <= n; i++) {
  //   sum += a[i];
  //   if (sum == mx) {
  //     std::cout << i << ' ';
  //     break;
  //   }
  // }

  // mx = -n, sum = 0;
  // for (int i = n; i >= 1; i--) {
  //   sum += a[i];
  //   mx = std::max(mx, sum);
  // }
  // sum = 0;
  // for (int i = n; i >= 1; i--) {
  //   sum += a[i];
  //   if (sum == mx) {
  //     std::cout << i << '\n';
  //     break;
  //   }
  // }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}