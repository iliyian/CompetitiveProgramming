#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::vector<int> l(sum + 1, -1), r(sum + 1, -1);
  int tot = 0;
  std::vector<std::vector<int>> b(n + 1);
  b[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < a[i]; j++) {
      int u = ++tot;
      if (j % 2 == 0) {
        l[b[i - 1][j / 2]] = u;
      } else {
        r[b[i - 1][j / 2]] = u;
      }
      b[i].push_back(u);
    }
  }
  std::cout << 1 << '\n';
  for (int i = 1; i <= sum; i++) {
    std::cout << l[i] << ' ' << r[i] << '\n';
  }
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