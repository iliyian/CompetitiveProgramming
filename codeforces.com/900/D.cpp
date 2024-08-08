// date: 2024-08-05 15:18:16
// tag: 数论，组合数，反演

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

std::map<int, int> m;

int dfs(int x) {
  if (x == 1) return 1;
  if (m[x]) return m[x];
  int ans = qpow(2, x - 1) - 1;
  ans = (ans % mod + mod) % mod;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans -= dfs(i);
      ans = (ans % mod + mod) % mod;
      if (i * i != x) {
        ans -= dfs(x / i);
        ans = (ans % mod + mod) % mod;
      }
    }
  }
  return m[x] = ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int x, y;
  std::cin >> x >> y;
  if (y % x) {
    std::cout << 0 << '\n';
    return 0;
  }

  std::cout << dfs(y / x) << '\n';

  return 0;
}