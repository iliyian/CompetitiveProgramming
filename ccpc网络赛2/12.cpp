#include <bits/stdc++.h>
using namespace std;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("12.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m - 1; j++) {
      if (a[i][j] != 'c' || a[i + 1][j] != 'p') {
        continue;
      }
      if (a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1] && a[i][j] != a[i + 1][j]) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}