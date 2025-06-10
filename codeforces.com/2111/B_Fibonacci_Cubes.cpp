#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int a = 1, b = 2;
  n -= 2;
  while (n--) {
    int c = a + b;
    a = b, b = c;
  }
  // std::cerr << a << ' ' << b << '\n';
  while (m--) {
    int x[3] {};
    for (int &i : x) std::cin >> i;
    std::sort(x, x + 3);
    std::cout << (x[0] >= b && x[2] >= a + b);
  }
  std::cout << '\n';
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