#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int cnt = 0;
  std::vector<std::array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    a[x][y]++;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (a[i][0] && a[i][1]) {
      ans += n - 2;
    }
    if (i > 0 && i < n) {
      if (a[i][0] && a[i + 1][1] && a[i - 1][1]) {
        ans++;
      }
      if (a[i][1] && a[i + 1][0] && a[i - 1][0]) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
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