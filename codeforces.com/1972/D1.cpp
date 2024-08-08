// date: 2024-08-06 16:17:59
// tag: 暴力，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  for (int b = 1; b <= m; b++) {
    for (int a = b; a <= n; a += b) {
      if ((a + b) % (b * b) == 0) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}