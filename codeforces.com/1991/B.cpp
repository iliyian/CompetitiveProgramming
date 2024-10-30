#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n + 1), a(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    std::cin >> b[i];
    for (int j = 30; j >= 0; j--) {
      if (b[i] >> j & 1) {
        a[i] |= 1 << j;
        a[i + 1] |= 1 << j;
      }
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    if ((a[i] & a[i + 1]) != b[i]) {
      std::cout << -1 << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
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