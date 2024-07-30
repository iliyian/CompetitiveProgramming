// date: 2024-07-29 14:45:14
// tag: 

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int ans[] = {0, 1, 2, 2, 3, 3, 4, 4, 4};

void solve() {
  int n;
  std::cin >> n;
  if (n <= 6) {
    std::cout << ans[n] << '\n';
    for (int i = 1; i <= n; i++) {
      std::cout << ans[i] << " \n"[i == n];
    }
  } else for (int i = 1; i <= n; i++) {
    if (i == 1) {
      std::cout << 4 << '\n';
    }
    std::cout << (i - 1) % 4 + 1 << " \n"[i == n];
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}