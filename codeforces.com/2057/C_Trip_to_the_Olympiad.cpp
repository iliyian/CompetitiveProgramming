#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int l, r;
  std::cin >> l >> r;
  int tl = l, tr = r;
  int t = 0;
  while (tl != tr) {
    tl >>= 1, tr >>= 1, t++;
  }
  int a = ((tl << t) ^ (1 << (t - 1)) - 1);
  int b = ((tl << t) ^ (1 << (t - 1)));
  // std::cout << (a ^ b) + (b ^ l) + (l ^ a) << '\n';
  std::cout << ' ' << a << ' ' << b << ' ';
  std::cout << (a == l || b == l ? r : l) << '\n';
  assert(l <= a && a <= r && l <= b && b <= r);
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}