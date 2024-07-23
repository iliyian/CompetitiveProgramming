// date: 2024-07-23 11:45:15
// tag: 构造，数学

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 2>> f(n + 2);
  std::string str;
  std::cin >> str;
  str = 'P' + str + 'S';
  std::vector<int> b(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int ans = 0;
  f[0] = {1, 0};
  std::set<int> s;
  for (int i = 1; i <= n + 1; i++) {
    int sum = b[i] + b[i - 1];
    if (str[i] == 'P' || str[i - 1] == 'S') continue;
    if (s.count(sum)) continue;
    s.insert(sum);

    for (int j = 1; j <= n + 1; j++) {
      f[j] = {0, 0};
    }

    for (int j = 1; j <= n + 1; j++) {
      if (str[j] != 'P') {
        if (str[j - 1] != 'S') {
          if (b[j] + b[j - 1] == sum) {
            f[j][1] += f[j - 1][0]; // PS
            f[j][1] %= mod;
          }
        }
        if (str[j - 1] != 'P') {
          int a = b[j - 1] - b[j]; // SS
          if (std::abs(a) <= m) {
            f[j][1] += f[j - 1][1];
            f[j][1] %= mod;
          }
        }
      }
      if (str[j] != 'S') {
        if (str[j - 1] != 'S') {
          int a = b[j] - b[j - 1]; // PP
          if (std::abs(a) <= m) {
            f[j][0] += f[j - 1][0];
            f[j][0] %= mod;
          }
        }
        if (str[j - 1] != 'P') {
          int s = b[j] + b[j - 1] - sum; // SP
          if (std::abs(s) <= m * 2) {
            f[j][0] += f[j - 1][1];
            f[j][0] %= mod;
          }
        }
      }
    }

    ans += f[n + 1][1];
    ans %= mod;
  }

  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}