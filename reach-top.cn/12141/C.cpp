#include <bits/stdc++.h>
#define int long long

bool isprime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  for (int i = 1000; i <= 9999; i++) {
    if (isprime(i) && isprime(i / 10) && isprime(i / 100) && isprime(i / 1000)) {
      std::cout << i;
      if (i != 7393) {
        std::cout << ',';
      }
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}