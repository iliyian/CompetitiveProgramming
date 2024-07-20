#include <bits/stdc++.h>
#define int long long
#define mod 998244353
// using namespace std;

std::vector<int> f(64);

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int solve(int x) {
  if (x == 1) return 1;
  for (int i = 62; i >= 1; i--) {
    if (x >> i & 1ll) {
      return ((f[i - 1] + solve(x - (1ll << i)) % mod) + (x ^ (1ll << i) % mod) % mod + 1) % mod;
    }
  }
  return 0;
}

int solve2(int x) {
  if (x == 1) return 1;
  int ans = x & 1;
  for (int i = 62; i >= 1; i--) {
    if (x >> i & 1ll) {
      ans += f[i - 1];
      ans %= mod;

      x ^= 1ll << i;
      ans += (x) % mod + 1;
      ans %= mod;
    }
  }
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  
  f[0] = 1;
  for (int i = 1; i <= 62; i++) {
    f[i] = (f[i - 1] * 2 % mod + qpow(2, i)) % mod;
  }

  // int cnt = 0;
  // for (int i = 1e12; i <= 1e12 + 500; i++) {
  //   cnt += __builtin_popcountll(i);
  //   cnt %= mod;
  // }
  // std::cout << cnt << ' ' << ((solve2(1e12+500) - solve2(1e12- 1)) % mod + mod) % mod << '\n';
  // // std::cout << cnt << ' ' << ((solve(1e12+500) - solve(1e12- 1)) % mod + mod) % mod << '\n';
  // return 0;

  int _;
  std::cin >> _;

  while (_--) {

  int l, r;
  std::cin >> l >> r;

  std::cout << ((solve2(r) - solve2(l - 1)) % mod + mod) % mod << '\n';

  }

  return 0;
}