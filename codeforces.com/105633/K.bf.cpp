#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    int x = 0;
    for (int j = 0; j < m; j++) {
      x ^= (int)(str[j] == 'Y') << j;
    }
    a[i] = x;
  }
  int mx = 0, x = -1, y = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((a[i] | a[j]) == (1ll << m) - 1 && __builtin_popcountll(a[i] & a[j]) > mx) {
        mx = __builtin_popcountll(a[i] & a[j]);
        x = i, y = j;
        // std::cout << i << ' ' << j << '\n';
        // return;
      }
    }
  }
  if (x == -1 && y == -1) {
    std::cout << "No\n";
    return;
  }
  std::cout << x << ' ' << y << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}