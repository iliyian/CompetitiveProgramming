#include <bits/stdc++.h>
#define int long long

constexpr int base = 129, mod = 1e9 + 123;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<int> h(n + 2), rh(n + 2), p(n + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * base % mod;
    h[i] = h[i - 1] * base % mod + str[i];
    h[i] %= mod;
  }
  for (int i = n; i >= 1; i--) {
    rh[i] = rh[i + 1] * base % mod + str[i];
    rh[i] %= mod;
  }
  auto check = [&](int l, int r) {
    return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod == (rh[l] - rh[r + 1] * p[r - l + 1] % mod + mod) % mod;
  };
  std::vector<std::array<int, 26>> s0(n + 1);
  std::vector<std::array<int, 26>> s1(n + 1);
  for (int i = 0; i < 26; i++) {
    s0[0][i] = 0;
    s1[1][i] = str[1] == i + 'a';
  }
  for (int i = 3; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (i % 2) {
        s1[i][j] = s1[i - 2][j] + (str[i] == 'a' + j);
      } else {
        s0[i][j] = s0[i - 2][j] + (str[i] == 'a' + j);
      }
    }
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}