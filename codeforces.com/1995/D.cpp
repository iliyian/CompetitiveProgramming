// date: 2024-07-24 10:19:13
// tag: 位运算，状压

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, c, k;
  std::cin >> n >> c >> k;
  std::vector<char> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> s(c + 1, std::vector<int>(n + 1));
  for (int i = 0; i < c; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = s[i][j - 1] + (a[j] - 'A' == i);
    }
  }
  std::vector<int> f(1 << c);
  for (int i = 1; i <= n - k + 1; i++) {
    int ms = 0;
    for (int j = 0; j < c; j++) {
      if (s[j][i + k - 1] - s[j][i - 1] > 0) {
        ms |= 1 << j;
      }
    }
    f[ms] = true;
  }
  f[(1 << (a.back() - 'A'))] = true;

  std::vector<int> bad(1 << c);
  for (int i = 0; i < (1 << c); i++) {
    bad[i ^ ((1 << c) - 1)] = f[i];
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < (1 << c); j++) {
      bad[j] |= bad[j | (1 << i)];
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < (1 << c); i++) {
    if (!bad[i]) {
      ans = std::min<int>(ans, __builtin_popcount(i));
    }
  };
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}