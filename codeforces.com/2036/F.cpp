// date: 2024-11-15 15:05:14
// tag: 位运算

#include <bits/stdc++.h>
#define int long long

int calc(int x) {
  int ans = 0, t = x;
  for (int j = 62; j >= 1; j--) {
    if (t >> j & 1) {
      ans ^= ((t - (1ll << j)) & 1 ^ 1) << j;
      t ^= 1ll << j;
    }
  }
  ans ^= ((x + 1) / 2) & 1;
  return ans;
}

int calc(int x, int i, int k) {
  int ans = calc(x);
  if (x < k) return ans;
  int mx = 0;
  for (int j = 62; j >= i; j--) {
    if (mx + k + (1ll << j) <= x) {
      mx += 1ll << j;
    }
  }
  mx >>= i;
  int cnt = mx + 1;
  if (cnt & 1) {
    ans ^= k;
  }
  ans ^= calc(mx) << i;
  return ans;
}

void solve() {
  int l, r, i, k;
  std::cin >> l >> r >> i >> k;
  std::cout << (calc(r, i, k) ^ calc(l - 1, i, k)) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};
