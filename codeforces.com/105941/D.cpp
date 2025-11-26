#include <bits/stdc++.h>
#define int long long

bool check(int n) {
  int s = std::sqrtl(n);
  return s * s == n;
}

void solve() {
  std::string s;
  std::cin >> s;
  int sum = 0;
  for (char i : s) {
    sum += i - '0';
  }
  std::cout << (check(sum) && check(std::stoll(s)) ? "Yes" : "No") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}