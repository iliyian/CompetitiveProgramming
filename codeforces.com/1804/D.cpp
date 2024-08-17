// date: 2024-08-11 15:05:15
// tag: 贪心，模拟，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  // int t;
  // std::cin >> t;
  // while (t--) {


  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = (ch == '1');
    }
  }
  int mn = 0;
  std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 1; j < m; j++) {
      if (a[i][j] && a[i][j + 1] && cur < m / 4) {
        cur++;
        vis[i][j] = vis[i][j + 1] = true;
        j++;
      }
    }
    for (int j = 1; j < m; j++) {
      if (!vis[i][j] && !vis[i][j + 1] && cur < m / 4) {
        cur += (a[i][j] || a[i][j + 1]);
        vis[i][j] = vis[i][j + 1] = true;
        j++;
      }
    }
    for (int j = 1; j <= m; j++) {
      cur += !vis[i][j] && a[i][j];
    }
    mn += cur;
  }
  std::cout << mn << ' ';

  for (auto &x : vis) {
    std::fill(x.begin(), x.end(), false);
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0, cnt = 0;
    for (int j = 1; j < m; j++) {
      if (!(a[i][j] && a[i][j + 1])) {
        cur++;
        j++;
      }
    }
    for (int j = 1; j <= m; j++) {
      cnt += a[i][j];
    }
    mx += cnt - std::max(0ll, m / 4 - cur); // -(1,1)=1
  }
  std::cout << mx << '\n';

  //   std::vector<std::pair<int, int>> p = {{}};
  //   int idx = 1;
  //   for (int i = 1; i <= m / 4 + m / 2; i++) {
  //     p.push_back({idx++, i <= m / 2 ? 1 : 2});
  //   }

  //   int nmn = LLONG_MAX, nmx = LLONG_MIN;
  //   do {
  //     int cur = 0, idx = 1;
  //     for (int i = 1; i <= m; i += p[idx++].second) {
  //       cur += (a[1][i] || a[1][i + p[idx].second - 1]);
  //     }
  //     nmn = std::min(nmn, cur);
  //     nmx = std::max(nmx, cur);
  //   } while (std::next_permutation(p.begin() + 1, p.end()));
  //   if (!(nmn == mn && nmx == mx)) {
  //     std::cout << mn << ' ' << mx << ' ' << nmn << ' ' << nmx << '\n';
  //     std::cout << "gg" << '\n';
  //     for (int j = 1; j <= m; j++) {
  //       std::cout << a[1][j];
  //     }
  //     std::cout << '\n';
  //   }

  // }

  return 0;
}