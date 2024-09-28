#include <bits/stdc++.h>
#include <cctype>
#define int long long

constexpr int mod = 998244353;

int id(char x) {
  if (std::isdigit(x)) return x - '0'; // [0,9]
  else if (isupper(x)) return x - 'A' + 10; // [10,35]
  else return x - 'a' + 37;// [37,61]
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  int ans = 1;
  std::vector<std::array<std::array<int, 8>, 62>> f(2);
  std::vector<std::array<int, 8>> g(2);
  // 10 + 26 + 26
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '?') {
      for (int j = 0; j < 62; j++) {
        int w = 0;
        if (j > 9) w = 1;
        if (j > 35) w = 2;
        for (int k = 0; k < 8; k++) {
          f[cur][j][k | (1 << w)] += g[cur ^ 1][k] - f[cur ^ 1][j][k];
        }
      }
    } else if (std::islower(str[i])) {
      f[cur][str[i] - ] += f[cur][str[]];
    } else {
      
    }
    for (int k = 0; k < 8; k++) {
      g[cur][k] += g[cur ^ 1][k];
    }
    cur ^= 1;
  }
  int ans = 0;
  if (str[n] == '?') {
    for (int j = 0; j < 62; j++) {
      for (int k = 1; k < 8; k++) {
        ans += f[cur ^ 1][j][k];
      }
    }
  } else if (isupper(str[n])) {

  }
  return 0;
}