#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define mod 998244353

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}

int inv(int x) { return qpow(x, mod - 2); }

int x, y, a0, a1, b, s, PA, PB;

int work(int a, int b) {
  if (a <= b) {
    if (b % a == 0) {
      return qpow(PA, b / a) % mod;
    } else {
      return qpow(PA, b / a) * work(a, b % a) % mod;
    }
  } else {
    if (a % b == 0) {
      return (mod + 1 - qpow(PB, a / b)) % mod;
    } else {
      return (mod + 1 -
              qpow(PB, a / b) * ((mod + 1 - work(a % b, b)) % mod) % mod) %
             mod;
    }
  }
}

void solve() {
  std::cin >> x >> y >> a0 >> a1 >> b;
  s = a0 + a1;
  PA = a0 % mod * inv(s) % mod;
  PB = a1 % mod * inv(s) % mod;
  std::cout << work(x, y) << '\n';
}

signed main() {
  freopen("G.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}