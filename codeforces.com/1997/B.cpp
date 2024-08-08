#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<char>> a(2, std::vector<char>(n + 1));
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 2; j <= n - 1; j++) {
      if (a[i][j] == '.' && a[i ^ 1][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.'
        && a[i ^ 1][j - 1] == 'x' && a[i ^ 1][j + 1] == 'x') {
          ans++;
        }
    }
  }
  std::cout << ans << '\n';
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