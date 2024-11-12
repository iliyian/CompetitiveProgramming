#include <bits/stdc++.h>
#define int long long

void solve() {
  int real = 0, n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int t = i;
    bool f = false;
    while (t >= 2) {
      if (n % t == 0) {
        real += n / t;
        f = true;
        break;
      }
      t--;
    }
    if (!f) {
      real += n;
    }
  }
  std::cout << real << '\n';

}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}