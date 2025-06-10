#include <bits/stdc++.h>
#define int long long

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

int inv(int x) {
  return qpow(x, mod - 2);
}

constexpr int N = 1e6;
int ans[N + 1];

void solve() {
  int n;
  std::cin >> n;
  std::cout << inv(ans[n]) << ' ';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  ans[1] = 1;
  for (int i = 2; i <= N; i++) {
    ans[i] = ans[i - 1] + __builtin_ctzll(i);
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}