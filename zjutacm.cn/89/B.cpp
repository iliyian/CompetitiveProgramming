#include <bits/stdc++.h>
#define int long long

void write(__int128 x) {
  if (x < 10) {
    std::cout << char(x + '0');
    return;
  }
  write(x / 10);
  std::cout << char(x % 10 + '0');
}

void solve() {
  int n;
  std::cin >> n;
  __int128 ans = n * (n + 1) / 2;
  ans = ans * ans;
  ans %= 998244353;
  write(ans);
  std::cout << '\n';
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