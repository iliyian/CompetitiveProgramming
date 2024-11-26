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
  std::string str;
  while (std::cin >> str) {
    if (str.size() > 5 || !isprime(std::stoll(str))) {
      std::cout << "No\n";
      continue;
    }
    std::cout << "Yes\n";
  }
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