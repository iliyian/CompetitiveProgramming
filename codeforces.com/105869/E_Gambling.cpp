#include <bits/stdc++.h>
#define int long long

std::map<std::pair<int, int>, int> mp;

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

const int inv2 = qpow(2, mod - 2);

int solve(int a, int b) {
  if (!a || !b) return 0;
  if (a < b) std::swap(a, b);
  if (mp.count({a, b})) return mp[{a, b}];
  return mp[{a, b}] = (1 + 1 + solve(a - b, b * 2)) % mod * inv2 % mod;
}

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::cout << solve(a, b) << '\n';
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