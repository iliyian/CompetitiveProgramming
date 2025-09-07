#include <bits/stdc++.h>
#define int long long

std::map<std::array<int, 4>, int> mp;
std::map<std::array<int, 4>, int> vis;

int solve(int n, int k, int s, int t) {
  if (mp.count({n, k, s, t})) return mp[{n, k, s, t}];
  if (s == t) return 0;
  if (vis[{n, k, s, t}]) return LLONG_MAX / 3;
  vis[{n, k, s, t}] = 1;
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    if (s >= i && n - s >= k - i) {
      ans = std::min(ans, solve(n, k, s - i + k - i, t) + 1);
    }
  }
  vis[{n, k, s, t}] = 0;
  return mp[{n, k, s, t}] = ans;
}

void solve() {
  
}

int check(int n, int k, int s, int t) {
  for (int i = 0; i <= s; i++) {
    if (i <= k && k - i <= n - s && s - i + k - i == t) {
      return true;
    }
  }
  return false;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  
  std::set<std::array<int, 4>> st;

  for (int n = 1; n <= 20; n++) {
    for (int k = 1; k <= n; k++) {
      std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, LLONG_MAX / 3));
      for (int i = 0; i <= n; i++) {
        dis[i][i] = 0;
      }
      for (int s = 0; s <= n; s++) {
        for (int t = 0; t <= n; t++) {
          if (check(n, k, s, t) && s != t) {
            dis[s][t] = 1;
          }
        }
      }
      for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
          for (int j = 0; j <= n; j++) {
            dis[i][j] = std::min(dis[i][j],  dis[i][k] + dis[k][j]);
          }
        }
      }
      std::map<int, int> mp;
      for (int d = 0; d <= n; d++) {
      // for (int s = 0; s <= n; s++) {
        // for (int t = 0; t <= n; t++) {
          int minans = LLONG_MAX / 3;
          // for (int a = 0; a <= 100; a++) {
          //   for (int b = (a == 0 ? 1 : 0); b <= 100; b++) {
          //     if ((a * n + b * d) % k == 0) {
          //       minans = std::min(minans, (a * n + b * d) / k);
          //     }
          //   }
          // }
          std::cout << n << ' ' << k << ' ' << d << ' ' << (minans == LLONG_MAX / 3 ? -1 : minans)
            << ' ' << (dis[0][d] == LLONG_MAX / 3 ? -1 : dis[0][d]) << '\n';
      // int g = std::gcd(std::gcd(n, k), d);
      // st.insert({n / g, k / g, d / g, dis[0][d / g] == LLONG_MAX / 3 ? -1 : dis[0][d / g]});
          // std::cout << n / g << ' ' << k / g << ' ' << d / g << ' ' << (dis[0][d / g] == LLONG_MAX / 3 ? -1 : dis[0][d / g]) << '\n';
          // if (mp.count(std::abs(s - t))) {
            // assert(dis[s][t] == mp[s ])
          // }
        // }
      }
    }
  }
  
  // for (auto [a, b, c, d] : st) {
  //   std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  // }

  return 0;

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}