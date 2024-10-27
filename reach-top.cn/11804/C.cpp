#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int sum = 0;
  bool f = n % 88 == 0;
  int t = n, cnt = 0;
  while (t) {
    cnt += t % 10 == 8;
    sum += t % 10;
    t /= 10;
  }
  std::cout << (n % 88 == 0 || cnt >= 2 ? sum : n % 10) << '\n';
  return 0;
}