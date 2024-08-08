// date: 2024-08-05 11:39:54
// tag: dp，字符串

#include <bits/stdc++.h>
#define int long long
#define N 100
// using namespace std;

constexpr int mod = 1e9 + 7;

std::vector<std::vector<int>> f(N + 1, std::vector<int>(26 * N + 1));

void solve() {
  std::string str;
  std::cin >> str;
  int sum = 0;
  for (auto ch : str) {
    sum += ch - 'a' + 1;
  }
  std::cout << (f[str.size()][sum] - 1 + mod) % mod << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  f[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N * 26; j++) {
      for (int k = 1; k <= std::min<int>(26, j); k++) {
        f[i][j] += f[i - 1][j - k];
        f[i][j] %= mod;
      }
    }
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}