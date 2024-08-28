// date: 2024-08-18 11:47:51
// tag: 根号分治

#include <bits/stdc++.h>
// #define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += i;
  }
  int len = 500;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(len + 1));
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= len; j++) {
      f[i][j] = (a[i] + j <= n ? f[a[i] + j][j] : 0) + 1;
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int p, k;
    std::cin >> p >> k;
    if (k <= len) {
      // int realans = 0, t = p;
      // while (t <= n) {
      //   t = a[t] + k;
      //   realans++;
      // }
      std::cout << f[p][k] << '\n';
      // assert(realans == f[p][k]);
    } else {
      int ans = 0;
      while (p <= n) {
        p = a[p] + k;
        ans++;
      }
      std::cout << ans << '\n';
    }
  }

  return 0;
}