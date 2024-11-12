#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << 100 << '\n';
  for (int i = 1; i <= 100; i++) {
    if (i <= 50) {
      std::cout << a << ' ';
    } else if (i <= 95) {
      std::cout << b << ' ';
    } else if (i <= 99) {
      std::cout << c << ' ';
    } else {
      std::cout << c + 1 << ' ';
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}